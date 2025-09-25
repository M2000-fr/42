/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:12:17 by mafritz           #+#    #+#             */
/*   Updated: 2025/01/20 11:25:54 by mafritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	check_file_permissions(t_minishell	*shell, char	*cmd)
{
	if (ft_strchr(cmd, '/') != NULL)
	{
		if (access(cmd, F_OK) == 0)
		{
			if (access(cmd, X_OK) == 0)
				return (1);
			else
			{
				shell->flag = INVALID_PERMISSIONS;
				return (-1);
			}
		}
		shell->flag = CMD_NOT_FOUND;
		return (-1);
	}
	return (0);
}

char	*check_path(t_minishell *shell, char **path, char *cmd)
{
	char	*tmp;
	int		i;

	if (check_file_permissions(shell, cmd) == 1)
		return (cmd);
	else if (check_file_permissions(shell, cmd) == -1)
		return (NULL);
	i = 0;
	while (path && path[i])
	{
		tmp = build_cmd(path[i], cmd);
		if (tmp)
		{
			if (access(tmp, F_OK) == 0)
			{
				if (access(tmp, X_OK) == 0)
					return (tmp);
			}
			free(tmp);
		}
		i++;
	}
	return (NULL);
}

int	try_execute_builtin(t_minishell *s, t_cmd	*c, t_builtins *b)
{
	int	cmd_status;

	cmd_status = ft_builtins(s, c, b);
	if (cmd_status != CMD_NOT_FOUND)
		return (cmd_status);
	return (CMD_NOT_FOUND);
}

int	execute_sys_bin(t_minishell *shell, t_cmd *cmd, char	**args)
{
	int	exec_value;

	if (!cmd->command || cmd->command[0] == '\0')
		return (CMD_NOT_FOUND);
	shell->path = check_path(shell, shell->env_path, cmd->command);
	if (!shell->path)
	{
		return (CMD_NOT_FOUND);
	}
	exec_value = execve(shell->path, args, shell->env);
	if (exec_value == -1)
		return (-1);
	return (1);
}

int	execute_local_bin(t_minishell *shell, t_cmd *cmd, char	**args)
{
	shell->path = check_path(shell, shell->env_path, cmd->command);
	if (shell->flag == INVALID_PERMISSIONS)
	{
		return (print_err(cmd->command, "permission denied", EMPTY_CMD));
	}
	if (!shell->path)
	{
		return (print_err(cmd->command, "command not found", CMD_NOT_FOUND));
	}
	if (!cmd->command || cmd->command[0] == '\0')
	{
		return (CMD_NOT_FOUND);
	}
	if (execve(cmd->command, args, shell->env) == -1)
	{
		return (-1);
	}
	return (0);
}
