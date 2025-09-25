/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:12:24 by mechard           #+#    #+#             */
/*   Updated: 2025/01/23 14:12:06 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_oldpwd(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
	{
		if (!ft_strncmp(env[i], "OLDPWD=", 7))
			return (*&env[i] + 7);
		i++;
	}
	return (NULL);
}

char	*get_pwd(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
	{
		if (!ft_strncmp(env[i], "PWD=", 4))
			return (env[i] + 4);
		i++;
	}
	return (NULL);
}

int	ft_pwd(t_minishell *shell, t_cmd *cmd)
{
	char	*pwd;

	pwd = shell->pwd;
	if (!pwd)
	{
		ft_putstr_fd("pwd: error retrieving current directory: getcwd: cannot access\
 parent directories: No such file or directory\n", 1);
		return (1);
	}
	if (cmd)
		(ft_putstr_fd(pwd, 1), ft_putchar_fd('\n', 1));
	return (0);
}

char	*ft_maj_pwd(t_minishell *shell)
{
	char	*home;
	char	**h;

	h = get_usr(shell->env);
	if (h)
	{
		home = ft_join_path(h);
		ft_dfree(h);
	}
	else
	{
		home = ft_strdup("/home/");
	}
	if (ft_strcmp(shell->pwd, home) && shell->pwd)
	{
		free(shell->pwd);
		shell->pwd = getcwd(NULL, 0);
	}
	free(home);
	return (shell->pwd);
}
