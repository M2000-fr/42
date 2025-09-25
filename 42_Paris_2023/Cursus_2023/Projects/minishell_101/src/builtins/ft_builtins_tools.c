/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:58:51 by mechard           #+#    #+#             */
/*   Updated: 2025/01/26 14:00:33 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_usr(char	**env)
{
	char	**str;
	int		i;

	i = 0;
	str = NULL;
	while (env && env[i])
	{
		if (!ft_strncmp(env[i], HOME, SIZE))
		{
			if (str)
				ft_dfree(str);
			str = ft_split(&env[i][SIZE], ENV_SEPARATOR);
			return (str);
		}
		i++;
	}
	return (NULL);
}

char	*ft_upoldpwd(t_minishell *shell, char *pwd)
{
	int		strncmp;
	int		i;

	i = 0;
	strncmp = ft_strncmp(shell->env[i], "OLDPWD=", 7);
	while (shell->env && shell->env[i] && !strncmp)
	{
		strncmp = ft_strncmp(shell->env[i], "OLDPWD=", 7);
		i++;
	}
	free(shell->env[i]);
	shell->env[i] = ft_strjoin("OLDPWD=", pwd);
	return (0);
}

char	*get_env_value(t_minishell *shell, const char *var_name)
{
	char	*value;
	size_t	var_len;
	int		strncmp;
	int		i;

	if (!shell || !shell->env || !var_name)
		return (ft_strdup(""));
	i = 0;
	var_len = ft_strlen(var_name);
	while (shell->env[i])
	{
		strncmp = ft_strncmp(shell->env[i], var_name, var_len);
		if (!strncmp && shell->env[i][var_len] == '=')
		{
			value = ft_strdup(shell->env[i] + var_len + 1);
			if (!value)
				return (ft_strdup(""));
			return (value);
		}
		i++;
	}
	return (ft_strdup(""));
}

void	handle_path(t_minishell	*shell, char	*var)
{
	if ((ft_strcmp(var, "PATH") == 0))
	{
		ft_dfree(shell->env_path);
		shell->env_path = get_env_path(shell->env);
	}
}
