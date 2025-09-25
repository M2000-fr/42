/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:54:46 by mechard           #+#    #+#             */
/*   Updated: 2025/01/21 14:43:21 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*add_char_to_buff(char	*buffer, int *i, int *len, char c)
{
	buffer = reallocate_buffer(buffer, len, *i + 1);
	if (!buffer)
		return (NULL);
	buffer[*i] = c;
	++(*i);
	return (buffer);
}

char	*allocate_empty_string(int size)
{
	char	*str;

	str = malloc(size);
	if (!str)
		return (NULL);
	ft_memset(str, 0, size);
	return (str);
}

int	update_quote_status(char c, char **s, t_status *quote)
{
	if (c == '\'' && *quote != STATUS_IN_DQUOTES)
	{
		++(*s);
		if (*quote == STATUS_IN_QUOTES)
			*quote = STATUS_OK;
		else
			*quote = STATUS_IN_QUOTES;
		return (1);
	}
	else if (c == '"' && *quote != STATUS_IN_QUOTES)
	{
		++(*s);
		if (*quote == STATUS_IN_DQUOTES)
			*quote = STATUS_OK;
		else
			*quote = STATUS_IN_DQUOTES;
		return (1);
	}
	return (0);
}

t_status	init_quote_status(void)
{
	return (STATUS_OK);
}

char	*add_var_value(t_interpolator *c)
{
	char	*var_value;
	size_t	len;

	len = compute_var_name_length(*(c->str));
	if (len == 0)
	{
		c->res = add_char_to_buff(c->res, c->res_i, c->len, **(c->str));
		++(*(c->str));
	}
	else
	{
		var_value = extract_variable_value(c->shell, *(c->str), len);
		if (!ft_strlen(var_value))
			c->shell->flag = EMPTY_PROMPT;
		if (!var_value)
			return (NULL);
		c->res = add_str_to_buff(c->res, c->res_i, c->len, var_value);
		*(c->str) += len + 1;
		free(var_value);
	}
	return (c->res);
}
