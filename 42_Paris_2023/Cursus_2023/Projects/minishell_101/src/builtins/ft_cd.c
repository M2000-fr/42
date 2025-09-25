/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:12:24 by mechard           #+#    #+#             */
/*   Updated: 2025/01/23 14:08:02 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_chdir(t_minishell *shell, char *target)
{
	char	*pwd;
	int		i;

	i = 0;
	if (chdir(target) != 0)
		return (print_errno(target, EXIT_FAILURE));
	pwd = getcwd(NULL, 0);
	while (shell->env && shell->env[i] && ft_strncmp(shell->env[i], "PWD=", 4))
		i++;
	free(shell->env[i]);
	shell->env[i] = ft_strjoin("PWD=", pwd);
	free(pwd);
	return (0);
}

int	ft_cd_core(t_minishell *shell, t_cmd *cmd)
{
	char	*pwd;
	char	*new_pwd;
	char	*oldpwd;
	char	*target;

	target = NULL;
	pwd = shell->pwd;
	if (!pwd)
		return (1);
	oldpwd = get_oldpwd(shell->env);
	if (!oldpwd)
		return (1);
	if (ft_strncmp(pwd, oldpwd, get_length(oldpwd, pwd)))
		ft_upoldpwd(shell, pwd);
	target = retrieve_target(shell, cmd, oldpwd);
	if (!target)
		return (1);
	if (ft_chdir(shell, target) != 0)
		return (free(target), 1);
	(free(target), new_pwd = getcwd(NULL, 0));
	(free(shell->pwd), shell->pwd = new_pwd);
	return (0);
}

int	ft_cd(t_minishell *shell, t_cmd *cmd)
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
	if (ft_dstrlen(cmd->args) > 1)
		return (free(home), print_err("cd", "too many arguments", 1));
	if (!shell->pwd)
		return (ft_printf("chdir: error retrieving current directory: getcwd: cannot access parent\
 directories: No such file or directory\n"), shell->pwd = home, 1);
	return (free(home), ft_cd_core(shell, cmd));
}
