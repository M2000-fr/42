/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:53:59 by mafritz           #+#    #+#             */
/*   Updated: 2025/01/26 13:39:39 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_outredir	retrieve_out_redir_type(t_token	*token)
{
	if (token->type == TOK_APPEND)
		return (REDIR_OUT_APPEND);
	if (token->type == TOK_OVERWRITE)
		return (REDIR_OUT_OVERWRITE);
	return (REDIR_OUT_NONE);
}

t_inredir	retrieve_in_redir_type(t_token	*token)
{
	if (token->type == TOK_INPUT)
		return (REDIR_IN_FILE);
	return (REDIR_IN_NONE);
}

t_token	*ft_parse_file_redir(t_cmd **cmd_head, t_token	*token)
{
	t_inredir	intype;
	t_token		*tmp;
	t_outredir	outtype;
	t_cmd		*cmd;

	tmp = token;
	if (no_str_found(tmp))
	{
		ft_cfree(*cmd_head);
		*cmd_head = NULL;
		return (NULL);
	}
	cmd = get_last_cmd(*cmd_head);
	if (!cmd || has_pipe_redir(cmd))
		cmd = add_cmd(cmd_head);
	intype = retrieve_in_redir_type(token);
	outtype = retrieve_out_redir_type(token);
	if (intype != REDIR_IN_NONE)
		cmd->file_redir.intype = intype;
	if (outtype != REDIR_OUT_NONE)
		cmd->file_redir.outtype = outtype;
	return (token->next);
}
