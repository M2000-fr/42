/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:08:03 by mafritz           #+#    #+#             */
/*   Updated: 2025/01/26 13:07:19 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_last_exit_code;

int	ft_exec_aux(t_minishell *shell, t_cmd *cmd)
{
	char	**args;
	int		cmd_status;

	if (!cmd || !cmd->command)
		return (EXIT_FAILURE);
	if (basic_precheck(shell, cmd) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	args = generate_argv_from_cmd(cmd);
	if (ft_strchr(cmd->command, '/') == NULL)
	{
		cmd_status = ft_builtins(shell, cmd, shell->builtins);
		if (cmd_status != CMD_NOT_FOUND)
			free_and_exit(shell, cmd, cmd_status, args);
		cmd_status = execute_sys_bin(shell, cmd, args);
		if (cmd_status != CMD_NOT_FOUND)
			free_and_exit(shell, cmd, cmd_status, args);
	}
	cmd_status = execute_local_bin(shell, cmd, args);
	if (cmd_status != CMD_NOT_FOUND)
		free_and_exit(shell, cmd, cmd_status, args);
	ft_dfree(args);
	return (cmd_status);
}

int	fd_check(t_cmd *c, t_fds *f, t_fds_list *node, t_fds_list	*list)
{
	t_fds	*prev_fds;

	prev_fds = NULL;
	if (node->prev)
		prev_fds = node->prev->fds;
	open_pipe_redir(c, f, prev_fds);
	if (open_file_redir(c, f) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	close_fds_list(list);
	return (EXIT_SUCCESS);
}

void	exec_stat_check(t_minishell	*shell, t_cmd	*cmd)
{
	t_cmd		*head;
	int			exec_status;

	head = cmd;
	exec_status = ft_exec_aux(shell, cmd);
	while (head && head->prev != NULL)
	{
		head = head->prev;
	}
	free_and_exit(shell, head, exec_status, NULL);
}

int	start_child_process(t_minishell *shell, t_cmd *cmd)
{
	t_fds_list	*current_node;
	t_fds_list	*fds_list;
	t_fds		*fds;
	int			current_pid;

	current_pid = -1;
	fds_list = NULL;
	while (current_pid != 0 && cmd)
	{
		fds = create_redir_fds();
		current_node = push_to_fds_list(&fds_list, fds, cmd);
		init_pipe_redir(cmd, fds);
		current_pid = fork();
		if (current_pid == -1)
			return (EXIT_FAILURE);
		else if (current_pid == 0)
		{
			if (fd_check(cmd, fds, current_node, fds_list) == EXIT_FAILURE)
				reset_free_exit(fds_list, shell, cmd);
			exec_stat_check(shell, cmd);
		}
		cmd = cmd->next;
	}
	reset_and_close_fds_list(fds_list);
	return (wait_for_children(current_pid));
}

int	ft_exec(t_minishell *shell, t_cmd *cmd_head)
{
	int	cmd_status;

	cmd_status = CMD_NOT_FOUND;
	if (cmd_head && !cmd_head->command)
	{
		return (0);
	}
	else if (!ft_strcmp(cmd_head->command, "exit"))
	{
		return (ft_exit(shell, cmd_head));
	}
	if (!cmd_head || !ft_strncmp(cmd_head->command, "!", 2)
		|| !ft_strncmp(cmd_head->command, ":", 2))
		return (-1);
	if (basic_precheck(shell, cmd_head) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (cmd_head->pipe_redir == PIPE_NONE)
		cmd_status = try_execute_builtin(shell, cmd_head, shell->builtins);
	if (cmd_status != CMD_NOT_FOUND)
		return (cmd_status);
	return (start_child_process(shell, cmd_head));
}
