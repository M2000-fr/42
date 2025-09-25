/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_text_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:49:31 by mafritz           #+#    #+#             */
/*   Updated: 2025/01/09 14:24:35 by mafritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	has_file_redir(t_cmd	*cmd)
{
	int	intype;
	int	outtype;

	intype = cmd->file_redir.intype != REDIR_IN_NONE;
	outtype = cmd->file_redir.outtype != REDIR_OUT_NONE;
	return (intype || outtype);
}

int	has_pipe_redir(t_cmd	*cmd)
{
	return (cmd->pipe_redir != PIPE_NONE);
}

t_cmd	*new_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->command = NULL;
	cmd->args = NULL;
	cmd->file_redir.outfile = NULL;
	cmd->file_redir.infile = NULL;
	cmd->file_redir.outtype = REDIR_OUT_NONE;
	cmd->file_redir.intype = REDIR_IN_NONE;
	cmd->pipe_redir = PIPE_NONE;
	cmd->prev = NULL;
	cmd->next = NULL;
	return (cmd);
}

void	copy_cmd(t_cmd *dest, t_cmd *orig)
{
	if (!dest || !orig)
		return ;
	if (orig->command)
		dest->command = ft_strdup(orig->command);
	if (orig->args)
		dest->args = ft_dstrdup(orig->args);
	if (orig->file_redir.outfile)
		dest->file_redir.outfile = ft_strdup(orig->file_redir.outfile);
	if (orig->file_redir.infile)
		dest->file_redir.infile = ft_strdup(orig->file_redir.infile);
	dest->file_redir.outtype = orig->file_redir.outtype;
	dest->file_redir.intype = orig->file_redir.intype;
	dest->pipe_redir = orig->pipe_redir;
}

t_cmd	*add_cmd(t_cmd	**head)
{
	t_cmd	*cmd;
	t_cmd	*last_cmd;

	cmd = new_cmd();
	if (!cmd)
		return (NULL);
	if (!*head)
		*head = cmd;
	else
	{
		last_cmd = *head;
		while (last_cmd->next)
			last_cmd = last_cmd->next;
		last_cmd->next = cmd;
		cmd->prev = last_cmd;
	}
	return (cmd);
}
