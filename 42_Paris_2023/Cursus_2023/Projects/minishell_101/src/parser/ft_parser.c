/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:44:30 by mechard           #+#    #+#             */
/*   Updated: 2025/01/26 13:40:27 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_token_list(t_token_line *tokenized_line)
{
	t_token	*token;
	t_token	*next_token;

	token = tokenized_line->token_list;
	while (token)
	{
		next_token = token->next;
		free(token->str);
		free(token);
		token = next_token;
	}
}

int	is_text(t_token *token)
{
	return (token->type == TOK_TEXT || token->type == TOK_SQUOTE_TEXT
		|| token->type == TOK_DQUOTE_TEXT);
}

t_cmd	*ft_parse_tokens(t_minishell *shell, t_token *token)
{
	t_cmd	*cmd;
	t_token	*prev_token;
	t_token	*tmp;

	cmd = NULL;
	prev_token = token;
	while (token)
	{
		tmp = token;
		if (is_text(token))
			token = ft_parse_text(&cmd, token, prev_token->type);
		else if (token->type == TOK_PIPE)
			token = ft_parse_pipe(&cmd, token);
		else if (token->type == TOK_HEREDOC)
			token = ft_parse_heredoc(shell, &cmd, token);
		else if (token->type == TOK_APPEND || token->type == TOK_OVERWRITE
			|| token->type == TOK_INPUT)
			token = ft_parse_file_redir(&cmd, token);
		prev_token = tmp;
	}
	return (cmd);
}

t_cmd	*ft_parser(t_minishell *shell, char *raw_user_input)
{
	t_cmd			*raw_cmd;
	t_cmd			*new_cmd;
	t_token_line	tokenized_line;

	raw_cmd = NULL;
	new_cmd = NULL;
	tokenized_line = ft_tokenizer(shell, raw_user_input);
	if (tokenized_line.status != STATUS_OK)
		return (free_token_list(&tokenized_line), NULL);
	raw_cmd = ft_parse_tokens(shell, tokenized_line.token_list);
	free_token_list(&tokenized_line);
	if (!raw_cmd)
		return (NULL);
	new_cmd = check_cmd(raw_cmd);
	ft_cfree(raw_cmd);
	return (new_cmd);
}
