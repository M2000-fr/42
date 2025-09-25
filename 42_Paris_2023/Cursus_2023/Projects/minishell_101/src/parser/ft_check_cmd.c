/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafritz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:10:29 by mafritz           #+#    #+#             */
/*   Updated: 2025/01/26 16:10:43 by mafritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	invalid_cmd(t_cmd	*cmd)
{
	char	*infile;
	char	*outfile;

	infile = cmd->file_redir.infile;
	outfile = cmd->file_redir.outfile;
	if (cmd->file_redir.intype != REDIR_IN_NONE && !infile)
	{
		return ((print_token_err("<", EXIT_FAILURE)));
	}
	else if (cmd->file_redir.outtype != REDIR_OUT_NONE && !outfile)
	{
		if (cmd->file_redir.outtype == REDIR_OUT_OVERWRITE)
		{
			return ((print_token_err(">", EXIT_FAILURE)));
		}
		else if (cmd->file_redir.outtype == REDIR_OUT_APPEND)
		{
			return ((print_token_err(">>", EXIT_FAILURE)));
		}
	}
	return (0);
}

t_cmd	*check_cmd(t_cmd *cmd)
{
	t_cmd	*new_cmd;
	t_cmd	*current;

	new_cmd = NULL;
	while (cmd)
	{
		if (invalid_cmd(cmd))
		{
			return (NULL);
		}
		if (cmd->command != NULL)
		{
			current = add_cmd(&new_cmd);
			copy_cmd(current, cmd);
		}
		cmd = cmd->next;
	}
	return (new_cmd);
}
