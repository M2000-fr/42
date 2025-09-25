/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_trois.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafritz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:06:32 by mafritz           #+#    #+#             */
/*   Updated: 2025/01/09 15:06:15 by mafritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static char	*trim_spaces(char *str)
{
	char	*result;
	char	*end;
	size_t	len;

	if (!str)
		return (NULL);
	while (ft_isspace((unsigned char)*str))
		str++;
	if (*str == '\0')
		return (ft_strdup(" "));
	end = str + ft_strlen(str) - 1;
	while (end > str && ft_isspace((unsigned char)*end))
		end--;
	len = end - str + 1;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	ft_strncpy(result, str, len);
	result[len] = '\0';
	return (result);
}

static char	*normalize_spaces(char	*str, int space)
{
	char	*dest;
	char	*src;

	src = str;
	dest = str;
	while (*src)
	{
		if (ft_isspace((unsigned char)*src))
		{
			if (!space)
			{
				*dest++ = ' ';
				space = 1;
			}
		}
		else
		{
			*dest++ = *src;
			space = 0;
		}
		src++;
	}
	*dest = '\0';
	return (str);
}

char	*cut_spaces(char	*str)
{
	char	*normalized;
	char	*trimmed;

	if (!str)
		return (NULL);
	trimmed = trim_spaces(str);
	if (!trimmed)
		return (NULL);
	normalized = normalize_spaces(trimmed, 0);
	if (!normalized)
	{
		free(trimmed);
		return (NULL);
	}
	return (normalized);
}

int	invalid_variable(char	*var)
{
	int	i;

	if (!var || *var == '\0')
		return (print_err(var, "variable name is empty or null", EXIT_FAILURE));
	i = 0;
	if (ft_isalpha(var[i]) == 0 && var[i] != '_')
		return (print_err(var, "not a valid identifier", EXIT_FAILURE));
	i++;
	while (var[i] && var[i] != '=')
	{
		if (ft_isalnum(var[i]) == 0 && var[i] != '_')
			return (print_err(var, "not a valid identifier", EXIT_FAILURE));
		i++;
	}
	if (var[i] == '=')
	{
		i++;
		while (var[i])
		{
			if (!ft_isprint(var[i]))
				return (print_err(var, INVALID_CHARACTER, EXIT_FAILURE));
			i++;
		}
	}
	return (0);
}
