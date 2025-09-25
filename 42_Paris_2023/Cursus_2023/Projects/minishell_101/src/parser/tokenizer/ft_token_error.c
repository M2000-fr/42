/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:20:07 by mechard           #+#    #+#             */
/*   Updated: 2024/12/30 12:32:39 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_invalid_token(char *str, int i)
{
	char	*res;
	int		start;
	int		end;

	start = i;
	end = i;
	res = NULL;
	while (str[end] && !ft_isspace(str[end]) && str[end] == str[i])
		++end;
	res = ft_substr(str, start, end - start);
	if (ft_strlen(res) >= 2)
	{
		res[2] = '\0';
		if (res[0] != res[1])
			res[1] = '\0';
	}
	return (res);
}

int	is_redir(t_v_token type)
{
	return (type == TOK_APPEND || type == TOK_OVERWRITE || type == TOK_INPUT);
}

int	is_invalid_token(t_token_line *l, t_v_token type)
{
	t_token	*last_token;

	if (type == TOK_INVALID)
		return (1);
	if (l->token_list == NULL)
		return (0);
	last_token = l->token_list;
	while (last_token->next)
		last_token = last_token->next;
	return (is_redir(last_token->type) && (type == TOK_PIPE || is_redir(type)));
}
