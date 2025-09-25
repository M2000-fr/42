/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_extract.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:33:55 by mafritz           #+#    #+#             */
/*   Updated: 2025/01/21 13:30:21 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	in_quotes(t_status status)
{
	return (status == STATUS_IN_QUOTES || status == STATUS_IN_DQUOTES);
}

int	is_quote(char c)
{
	return (c == '\'' || c == '"');
}

void	push_text_token(t_token_line	*l, char	*str, int start, int end)
{
	t_v_token	type;

	type = TOK_TEXT;
	if (end > start)
		push_token(l, ft_substr(str, start, end - start), type);
}

int	extract_text_token(char	*s, t_token_line	*l, int i)
{
	t_status	old;
	int			start;
	int			end;
	int			text;

	start = i;
	end = i;
	text = retrieve_token_type(s, end) == TOK_TEXT;
	l->status = update_status(s, i, l);
	while (s[end] && (text || in_quotes(l->status)))
	{
		++end;
		old = l->status;
		l->status = update_status(s, end, l);
		if (in_quotes(old) && !in_quotes(l->status) && ft_isspace(s[end + 1]))
		{
			++end;
			break ;
		}
		text = retrieve_token_type(s, end) == TOK_TEXT;
	}
	i = end;
	push_text_token(l, s, start, end);
	return (i);
}

int	extract_next_token(char	*str, t_token_line	*l, int i)
{
	t_v_token	type;

	i = skip_spaces(str, i);
	type = retrieve_token_type(str, i);
	if (is_invalid_token(l, type))
		return (print_invalid_token_msg(str, i), -1);
	if (type == TOK_TEXT)
		return (extract_text_token(str, l, i));
	else if (type != TOK_TEXT && type != TOK_END)
	{
		push_token(l, ft_substr(str, i, get_sep_len(type)), type);
		return (i + get_sep_len(type));
	}
	else if (type == TOK_END)
		return (i);
	i = skip_spaces(str, i);
	return (i);
}
