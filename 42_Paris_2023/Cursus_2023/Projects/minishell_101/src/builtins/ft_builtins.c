/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:21:16 by mechard           #+#    #+#             */
/*   Updated: 2025/01/26 13:12:48 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_retrievebi(char *cmd, t_builtins *builtins)
{
	int			i;

	if (!cmd)
		return (0);
	i = 0;
	while (i < 7)
	{
		if (!ft_strcmp(cmd, builtins->dic[i]))
			return (i + 1);
		i++;
	}
	return (-1);
}

int	ft_builtins(t_minishell *shell, t_cmd	*cmd, t_builtins *builtins)
{
	t_builtin	exec;
	t_fds		*fds;
	int			status;

	if (!shell || shell->path)
		return (0);
	if (!builtins)
		return (0);
	if (ft_retrievebi(cmd->command, builtins) < 0)
		return (CMD_NOT_FOUND);
	else
		exec = builtins->builtins[(ft_retrievebi(cmd->command, builtins) - 1)];
	fds = create_redir_fds();
	status = init_file_redir(cmd, fds);
	if (!status)
		status = exec(shell, cmd);
	reset_file_redir(fds);
	close_redir_fds(fds);
	destroy_redir_fds(fds);
	return (status);
}
