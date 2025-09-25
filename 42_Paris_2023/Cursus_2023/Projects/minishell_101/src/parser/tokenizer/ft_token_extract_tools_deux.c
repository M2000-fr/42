/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_extract_tools_deux.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:48:27 by mafritz           #+#    #+#             */
/*   Updated: 2025/01/21 13:58:00 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_type(t_token *token, int type)
{
	token->type = type;
	token->next = NULL;
}

void	push_token(t_token_line *line, char *token, int type)
{
	t_token	*new_token;
	t_token	*last_token;

	if (!token)
		return ;
	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return ;
	new_token->str = ft_strdup(token);
	free(token);
	if (!new_token->str)
	{
		free(new_token);
		return ;
	}
	set_type(new_token, type);
	if (!line->token_list)
		line->token_list = new_token;
	else
	{
		last_token = line->token_list;
		while (last_token->next)
			last_token = last_token->next;
		last_token->next = new_token;
	}
}

int	ft_token_redir(char *raw_str, int i)
{
	if (raw_str[i] == '<')
	{
		if (raw_str[i + 1] == '<' && !is_redir_char(raw_str[i + 2]))
			return (TOK_HEREDOC);
		else if (!is_redir_char(raw_str[i + 1]))
			return (TOK_INPUT);
		else
			return (TOK_INVALID);
	}
	if (raw_str[i] == '>')
	{
		if (raw_str[i + 1] == '>' && !is_redir_char(raw_str[i + 2]))
			return (TOK_APPEND);
		else if (!is_redir_char(raw_str[i + 1]))
			return (TOK_OVERWRITE);
		else
			return (TOK_INVALID);
	}
	return (-1);
}
