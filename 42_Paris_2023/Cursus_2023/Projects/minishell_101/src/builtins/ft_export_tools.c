/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:12:41 by mafritz           #+#    #+#             */
/*   Updated: 2025/01/09 14:07:43 by mafritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	free_var_val(char	*var, char	*val)
{
	free(var);
	free(val);
}

size_t	count_env(char **env)
{
	size_t	count;

	count = 0;
	while (env[count])
		count++;
	return (count);
}

char	*find_equal_sign(char *arg)
{
	char	*equal_sign;

	equal_sign = ft_strchr(arg, '=');
	if (!equal_sign)
		return (NULL);
	return (equal_sign);
}

void	ft_export_wa(t_minishell *shell)
{
	int	i;

	i = 0;
	while (shell->env[i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(shell->env[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}

void	append_variable_to_env(char	*env, char	*var, char	*val)
{
	ft_strcpy(env, var);
	ft_strcat(env, "=");
	ft_strcat(env, val);
}
