/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:12:09 by mafritz           #+#    #+#             */
/*   Updated: 2025/01/26 13:34:59 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_fds(t_fds *fds)
{
	if (!fds)
		return ;
	fds->infile = NULL;
	fds->outfile = NULL;
	fds->fd_in = -1;
	fds->fd_out = -1;
	fds->pipe_fd = NULL;
	fds->in_backup = -1;
	fds->out_backup = -1;
	fds->pid = -1;
}

int	basic_precheck(t_minishell *shell, t_cmd	*cmd)
{
	if (!shell || !cmd->command)
		return (EXIT_FAILURE);
	return (CMD_NOT_FOUND);
}

char	**generate_argv_from_cmd(t_cmd	*cmd)
{
	char	**argv;
	int		i;
	int		num_args;

	i = 0;
	num_args = ft_dstrlen(cmd->args);
	argv = malloc((num_args + 2) * sizeof(char *));
	argv[0] = ft_strdup(cmd->command);
	argv[num_args + 1] = NULL;
	if (cmd->args)
	{
		while (cmd->args[i])
		{
			argv[i + 1] = ft_strdup(cmd->args[i]);
			++i;
		}
	}
	return (argv);
}

void	free_and_exit(t_minishell	*s, t_cmd	*c, int stat, char **a)
{
	if (a)
	{
		ft_dfree(a);
	}
	ft_allfree(s, c);
	exit_shell(stat, 0);
}
