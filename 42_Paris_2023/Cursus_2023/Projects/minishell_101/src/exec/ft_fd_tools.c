/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:14:28 by mafritz           #+#    #+#             */
/*   Updated: 2025/01/26 13:07:26 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_fds	*create_redir_fds(void)
{
	t_fds	*fds;

	fds = (t_fds *)malloc(sizeof(t_fds));
	init_fds(fds);
	return (fds);
}

int	open_file_redir(t_cmd	*cmd, t_fds	*fds)
{
	int	outfile;
	int	infile;

	outfile = cmd->file_redir.outtype != REDIR_OUT_NONE;
	infile = cmd->file_redir.intype != REDIR_IN_NONE;
	if (outfile || infile)
		return (init_file_redir(cmd, fds));
	return (0);
}

t_fds_list	*push_to_fds_list(t_fds_list	**head, t_fds	*fds, t_cmd	*cmd)
{
	t_fds_list	*new_node;
	t_fds_list	*last;

	new_node = (t_fds_list *)malloc(sizeof(t_fds_list));
	new_node->cmd = cmd;
	new_node->fds = fds;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!*head)
	{
		*head = new_node;
		return (new_node);
	}
	last = *head;
	while (last->next)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
	return (new_node);
}

void	reset_and_close_fds_list(t_fds_list	*head)
{
	reset_fds_list(head);
	close_fds_list(head);
}

void	reset_free_exit(t_fds_list	*list, t_minishell	*shell, t_cmd	*cmd)
{
	reset_and_close_fds_list(list);
	free_and_exit(shell, cmd, 1, NULL);
}
