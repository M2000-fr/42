/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:55:42 by mafritz           #+#    #+#             */
/*   Updated: 2025/01/26 13:46:54 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*get_last_cmd(t_cmd	*head)
{
	t_cmd	*cmd;

	if (!head)
		return (NULL);
	cmd = head;
	while (cmd->next)
		cmd = cmd->next;
	return (cmd);
}

t_token	*ft_parse_pipe(t_cmd **cmd_head, t_token	*token)
{
	t_cmd	*cmd;

	cmd = get_last_cmd(*cmd_head);
	if (!cmd)
	{
		print_token_err(token->str, EXIT_FAILURE);
		return (NULL);
	}
	cmd->pipe_redir = PIPE_IN;
	return (token->next);
}
