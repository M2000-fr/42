/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:00:01 by mafritz           #+#    #+#             */
/*   Updated: 2025/01/26 13:47:30 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_shell(int ret_code, int free_history)
{
	if (free_history)
	{
		rl_clear_history();
	}
	exit(ret_code);
}

void	close_pipe_fds(t_fds	*fds)
{
	if (fds->pipe_fd)
		(close(fds->pipe_fd[0]), close(fds->pipe_fd[1]));
}

int	wait_for_children(int last_pid)
{
	pid_t	wpid;
	int		status;
	int		save_status;

	save_status = 0;
	while (1)
	{
		wpid = waitpid(-1, &status, 0);
		if (wpid == -1)
			break ;
		if (wpid == last_pid)
			save_status = status;
	}
	if (WIFSIGNALED(save_status))
		status = 128 + WTERMSIG(save_status);
	else if (WIFEXITED(save_status))
		status = WEXITSTATUS(save_status);
	else
		status = save_status;
	return (status);
}
