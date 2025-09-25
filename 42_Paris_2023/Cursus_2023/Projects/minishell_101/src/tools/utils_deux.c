/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_deux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:56:03 by mafritz           #+#    #+#             */
/*   Updated: 2025/01/26 13:43:25 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	try_open_outfile(t_cmd	*cmd, char	*outfile, t_fds	*fds)
{
	if (cmd->file_redir.outtype == REDIR_OUT_OVERWRITE)
	{
		if (!outfile)
			return (print_token_err("newline", EXIT_FAILURE));
		fds->fd_out = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fds->fd_out == -1)
			return (print_errno(outfile, EXIT_FAILURE));
	}
	else if (cmd->file_redir.outtype == REDIR_OUT_APPEND)
	{
		if (!outfile)
			return (print_token_err("newline", EXIT_FAILURE));
		fds->fd_out = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fds->fd_out == -1)
			return (print_errno(outfile, EXIT_FAILURE));
	}
	return (0);
}

int	is_directory(char	*str)
{
	struct stat	cmd_stat;

	ft_memset(&cmd_stat, 0, sizeof(cmd_stat));
	stat(str, &cmd_stat);
	return (S_ISDIR(cmd_stat.st_mode));
}

void	check_status(t_token_line	*token_line)
{
	if (token_line->status != STATUS_OK)
		ft_printf("Syntax error: Unterminated quoted string\n");
}

int	ft_isspace(char c)
{
	if ((c > 8 && c < 14) || (c == 32))
		return (1);
	return (0);
}

int	skip_spaces(char	*str, int i)
{
	while (str[i] && ft_isspace(str[i]))
		++i;
	return (i);
}
