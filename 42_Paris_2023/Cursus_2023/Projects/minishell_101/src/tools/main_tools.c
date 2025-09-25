/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:08:41 by mafritz           #+#    #+#             */
/*   Updated: 2025/01/26 14:01:21 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	search_env_variable(char	**env, char	*var)
{
	char	*tmp_var;
	int		i;

	tmp_var = ft_strjoin(var, "=");
	if (!tmp_var)
	{
		return (-1);
	}
	i = 0;
	while (env[i])
	{
		if (ft_strcmp(tmp_var, env[i]) == 0)
		{
			free(tmp_var);
			return (i);
		}
		i++;
	}
	free(tmp_var);
	return (-1);
}

int	check_cmd_status(t_minishell	*shell, t_cmd	*cmd)
{
	char	*ft_str;
	int		search_env;

	if (shell->flag == EMPTY_PROMPT)
		return (0);
	if ((shell->flag != EMPTY_STR) && (!cmd || !cmd->command))
		return (0);
	if ((shell->flag == EMPTY_STR) && (!cmd || !cmd->command))
		return (print_err("command not found", "", CMD_NOT_FOUND));
	ft_str = ft_strchr(cmd->command, '/');
	search_env = search_env_variable(shell->env, cmd->command);
	if (ft_str == 0 && search_env != -1)
		return (print_err("command not found", cmd->command, CMD_NOT_FOUND));
	else if (is_directory(cmd->command))
		return (print_err(IS_DIR, cmd->command, EMPTY_CMD));
	return (EXIT_SUCCESS);
}

int	check_and_execute(t_minishell	*shell, t_cmd	*cmd)
{
	int			cmd_status;

	cmd_status = check_cmd_status(shell, cmd);
	if (cmd_status == EXIT_SUCCESS)
	{
		return (ft_exec(shell, cmd));
	}
	else
	{
		return (cmd_status);
	}
}

int	ctrl_d_handling(char	*str, char	*message)
{
	if (!str)
	{
		printf("%s\n", message);
		return (1);
	}
	return (0);
}
