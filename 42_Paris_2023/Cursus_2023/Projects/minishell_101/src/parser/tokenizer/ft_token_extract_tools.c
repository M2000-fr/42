/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_extract_tools.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:47:15 by mafritz           #+#    #+#             */
/*   Updated: 2025/01/21 13:47:29 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redir_char(char c)
{
	return (c == '<' || c == '>' || c == '|');
}

t_v_token	retrieve_token_type(char	*raw_str, int i)
{
	if (ft_isspace(raw_str[i]))
		return (TOK_SPACE);
	if (raw_str[i] == '|')
		return (TOK_PIPE);
	if (raw_str[i] == '<' || raw_str[i] == '>')
		return (ft_token_redir(raw_str, i));
	if (raw_str[i] == '\'' && ft_strlen(raw_str) == 2)
		return (TOK_SQUOTE_TEXT);
	if (raw_str[i] == '\"' && ft_strlen(raw_str) == 2)
		return (TOK_DQUOTE_TEXT);
	if (raw_str[i] == '\0')
		return (TOK_END);
	return (TOK_TEXT);
}

int	get_sep_len(t_v_token type)
{
	if (type == TOK_APPEND || type == TOK_HEREDOC)
		return (2);
	return (1);
}

t_token_line	init_token_line(void)
{
	t_token_line	token_line;

	token_line.token_list = NULL;
	token_line.status = STATUS_OK;
	return (token_line);
}

t_status	update_status(char	*raw_str, int i, t_token_line *l)
{
	if (raw_str[i] == '\'' && l->status != STATUS_IN_DQUOTES)
	{
		if (l->status == STATUS_IN_QUOTES)
			return (STATUS_OK);
		return (STATUS_IN_QUOTES);
	}
	else if (raw_str[i] == '"' && l->status != STATUS_IN_QUOTES)
	{
		if (l->status == STATUS_IN_DQUOTES)
			return (STATUS_OK);
		return (STATUS_IN_DQUOTES);
	}
	return (l->status);
}
