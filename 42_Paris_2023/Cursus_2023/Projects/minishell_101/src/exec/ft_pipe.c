/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:15:00 by mafritz           #+#    #+#             */
/*   Updated: 2024/12/30 14:34:52 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	open_pipe_redir(t_cmd *cmd, t_fds *fds, t_fds *prev_fds)
{
	if (!fds->pipe_fd)
		return (0);
	if (!cmd)
		return (0);
	if (cmd->pipe_redir == PIPE_IN)
		dup2(fds->pipe_fd[1], STDOUT_FILENO);
	if (cmd->prev && cmd->prev->pipe_redir == PIPE_IN)
		dup2(prev_fds->pipe_fd[0], STDIN_FILENO);
	return (1);
}

int	init_pipe(t_cmd	*cmd, t_fds *fds)
{
	int			*fd;
	int			pipe_exists;
	int			prev_pipe;

	pipe_exists = cmd->pipe_redir == PIPE_IN;
	prev_pipe = (cmd->prev && cmd->prev->pipe_redir == PIPE_IN);
	if (pipe_exists || prev_pipe)
	{
		fd = malloc(sizeof * fd * 2);
		if (!fd || pipe(fd) != 0)
			return (free(fd), 0);
		fds->pipe_fd = fd;
	}
	return (1);
}

void	init_pipe_redir(t_cmd	*cmd, t_fds	*fds)
{
	int	pipe_exists;
	int	prev_pipe_exists;

	pipe_exists = cmd->pipe_redir != PIPE_NONE;
	prev_pipe_exists = (cmd->prev && cmd->prev->pipe_redir != PIPE_NONE);
	if (pipe_exists || prev_pipe_exists)
		init_pipe(cmd, fds);
}
