/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:10:49 by mafritz           #+#    #+#             */
/*   Updated: 2025/01/26 13:35:52 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	io_check(t_fds *fds)
{
	if (!fds || (!fds->infile && !fds->outfile))
		return (1);
	else if ((fds->infile && fds->fd_in == -1) || (fds->outfile
			&& fds->fd_out == -1))
		return (0);
	return (1);
}

int	reset_file_redir(t_fds *fds)
{
	if (!fds)
		return (0);
	if (fds->in_backup != -1)
	{
		if (dup2(fds->in_backup, STDIN_FILENO) == -1)
			return (0);
		close(fds->in_backup);
		fds->in_backup = -1;
	}
	if (fds->out_backup != -1)
	{
		if (dup2(fds->out_backup, STDOUT_FILENO) == -1)
			return (0);
		close(fds->out_backup);
		fds->out_backup = -1;
	}
	return (1);
}

int	open_redir_files(t_cmd *cmd, t_fds *fds)
{
	char	*infile;
	char	*outfile;
	int		error;

	infile = cmd->file_redir.infile;
	outfile = cmd->file_redir.outfile;
	error = EXIT_FAILURE;
	if (cmd->file_redir.intype == REDIR_IN_FILE)
	{
		if (!infile)
			return (print_token_err("newline", error));
		fds->fd_in = open(infile, O_RDONLY);
		if (fds->fd_in == -1)
			return (print_errno(infile, error));
	}
	if (cmd->file_redir.outtype == REDIR_OUT_OVERWRITE)
	{
		return (try_open_outfile(cmd, outfile, fds));
	}
	if (cmd->file_redir.outtype == REDIR_OUT_APPEND)
	{
		return (try_open_outfile(cmd, outfile, fds));
	}
	return (0);
}

int	check_fd_backup(t_fds *fds)
{
	if (!fds)
		return (EXIT_FAILURE);
	fds->in_backup = dup(STDIN_FILENO);
	if (fds->in_backup == -1)
		return (EXIT_FAILURE);
	fds->out_backup = dup(STDOUT_FILENO);
	if (fds->out_backup == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	init_file_redir(t_cmd *cmd, t_fds *fds)
{
	int	status;

	if (check_fd_backup(fds) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	status = open_redir_files(cmd, fds);
	if (!status)
	{
		if (fds->fd_in != -1)
			if (dup2(fds->fd_in, STDIN_FILENO) == -1)
				return (EXIT_FAILURE);
		if (fds->fd_out != -1)
			if (dup2(fds->fd_out, STDOUT_FILENO) == -1)
				return (EXIT_FAILURE);
	}
	return (status);
}
