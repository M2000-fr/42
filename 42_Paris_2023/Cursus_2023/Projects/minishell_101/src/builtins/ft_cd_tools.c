/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:08:47 by mafritz           #+#    #+#             */
/*   Updated: 2025/01/26 15:18:11 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_cdwa(t_cmd *cmd)
{
	char	*target;

	target = NULL;
	if (!cmd->command || !cmd->args[0] || cmd->args[1])
		return (ft_printf("error cmd !"), NULL);
	else
	{
		if (!ft_strncmp(cmd->args[0], "/home", 5))
			target = ft_strdup(cmd->args[0]);
		else if (!ft_strncmp(cmd->args[0], "../", 3))
			target = ft_strdup(cmd->args[0]);
		else
			target = ft_strdup(cmd->args[0]);
		if (!target)
			ft_printf("Only a relative or absolute path is accepted !");
	}
	return (target);
}

int	ft_cd_error(char *str)
{
	if (!str)
		return (1);
	ft_putstr_fd("cd: string not in pwd: ", 1);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

int	get_length(char	*oldpwd, char	*pwd)
{
	int	old_len;
	int	new_len;

	old_len = ft_strlen(oldpwd);
	new_len = ft_strlen(pwd);
	if (new_len > old_len)
		return (new_len);
	return (old_len);
}

char	*ft_join_path(char	**dstr)
{
	char	*str;
	char	*tmp;
	int		len;
	int		i;

	i = 0;
	len = ft_dstrlen(dstr);
	str = ft_strdup("/");
	while (i < len - 1)
	{
		tmp = ft_strjoin(str, dstr[i++]);
		free(str);
		str = ft_strjoin(tmp, "/");
		free(tmp);
	}
	tmp = ft_strjoin(str, dstr[i]);
	free(str);
	str = tmp;
	return (str);
}

char	*retrieve_target(t_minishell	*shell, t_cmd	*cmd, char	*oldpwd)
{
	char	*target;
	char	**home;

	target = NULL;
	(void)oldpwd;
	if (ft_dstrlen(cmd->args) == 0)
	{
		home = get_usr(shell->env);
		if (home)
		{
			target = ft_join_path(home);
			ft_dfree(home);
		}
		else
		{
			target = ft_strdup("/home/");
		}
	}
	else if (ft_dstrlen(cmd->args) == 1)
		target = ft_cdwa(cmd);
	else
		ft_cd_error(cmd->args[0]);
	return (target);
}
