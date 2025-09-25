/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_cleanup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:16:38 by mafritz           #+#    #+#             */
/*   Updated: 2025/01/26 13:37:04 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_redir_fds(t_fds	*fds)
{
	if (!fds)
		return ;
	if (fds->fd_in != -1)
		close(fds->fd_in);
	if (fds->fd_out != -1)
		close(fds->fd_out);
	if (fds->in_backup != -1)
		close(fds->in_backup);
	if (fds->out_backup != -1)
		close(fds->out_backup);
	close_pipe_fds(fds);
}

void	close_fds_list(t_fds_list	*head)
{
	t_fds_list	*current;
	t_fds_list	*next;

	current = head;
	while (current)
	{
		next = current->next;
		close_redir_fds(current->fds);
		destroy_redir_fds(current->fds);
		free(current);
		current = next;
	}
}

void	destroy_redir_fds(t_fds	*fds)
{
	if (fds->pipe_fd)
		free(fds->pipe_fd);
	free(fds);
}

void	reset_fds_list(t_fds_list	*head)
{
	t_fds_list	*current;

	current = head;
	if (!current)
	{
		return ;
	}
	while (current)
	{
		reset_file_redir(current->fds);
		current = current->next;
	}
}
