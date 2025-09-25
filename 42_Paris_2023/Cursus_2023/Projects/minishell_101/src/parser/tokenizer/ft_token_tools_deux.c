/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_tools_deux.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:22:29 by mafritz           #+#    #+#             */
/*   Updated: 2024/12/30 13:30:21 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_variable_value(t_minishell *s, char *str, int len)
{
	char	*var_value;
	char	*var_name;

	var_value = NULL;
	if (str[1] == '?')
		return (ft_itoa(g_last_exit_code));
	else if (ft_isalpha(str[1]) || str[1] == '_')
	{
		var_name = strndup(str + 1, len);
		var_value = get_env_value(s, var_name);
		free(var_name);
	}
	return (var_value);
}

int	compute_var_name_length(char	*str)
{
	char	*current;

	current = str + 1;
	while (*current && !ft_isdigit(*current))
	{
		if (*current == '?')
			return (1);
		else if (ft_isalnum(*current) || *current == '_')
			++current;
		else
			break ;
	}
	if (ft_isdigit(*current))
		current++;
	return (current - str - 1);
}

char	*reallocate_buffer(char	*buff, int *size, int new_size)
{
	char	*new_buff;
	int		old_size;

	new_buff = NULL;
	old_size = *size;
	if (new_size >= (*size - 1))
	{
		*size = new_size * 2;
		new_buff = malloc(*size);
		if (!new_buff)
			return (free(buff), NULL);
		ft_memcpy(new_buff, buff, old_size);
		free(buff);
		buff = new_buff;
	}
	return (buff);
}

char	*add_str_to_buff(char	*buff, int *i, int *len, char	*str)
{
	int	str_len;

	if (!str)
		return (buff);
	str_len = strlen(str);
	buff = reallocate_buffer(buff, len, *i + str_len + 1);
	if (!buff)
		return (NULL);
	ft_memcpy(buff + *i, str, str_len);
	*i += str_len;
	return (buff);
}
