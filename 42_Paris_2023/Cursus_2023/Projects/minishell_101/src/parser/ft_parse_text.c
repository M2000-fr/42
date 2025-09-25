/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:41:40 by mafritz           #+#    #+#             */
/*   Updated: 2025/01/21 12:01:27 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	invalid_infile(t_cmd	*cmd)
{
	char	*infile;

	infile = cmd->file_redir.infile;
	if (cmd->file_redir.intype != REDIR_IN_NONE && access(infile, F_OK) != 0)
	{
		print_errno(infile, EXIT_FAILURE);
		return (1);
	}
	return (0);
}

t_token	*handle_file_name(t_cmd	*c, t_token	*t, t_v_token last_type)
{
	int	fd;

	if (has_file_redir(c))
	{
		if (last_type == TOK_INPUT)
		{
			if (c->file_redir.infile)
				free(c->file_redir.infile);
			c->file_redir.infile = ft_strdup(t->str);
		}
		else if (last_type == TOK_APPEND || last_type == TOK_OVERWRITE)
		{
			if (c->file_redir.outfile)
				free(c->file_redir.outfile);
			c->file_redir.outfile = ft_strdup(t->str);
			if (!invalid_infile(c))
			{
				fd = open(c->file_redir.outfile, O_WRONLY | O_CREAT, 0644);
				close (fd);
			}
		}
	}
	return (t->next);
}

int	need_push_cmd(t_cmd *cmd)
{
	return (!cmd || !(has_file_redir(cmd) && !has_pipe_redir(cmd)));
}

int	is_text_token(t_token	*token)
{
	int	text;
	int	squote;
	int	dquote;

	text = token->type == TOK_TEXT;
	squote = token->type == TOK_SQUOTE_TEXT;
	dquote = token->type == TOK_DQUOTE_TEXT;
	return (text || squote || dquote);
}

t_token	*ft_parse_text(t_cmd **h, t_token	*t, t_v_token last_type)
{
	t_cmd	*cmd;

	cmd = get_last_cmd(*h);
	if ((cmd) && has_file_redir(cmd) && !has_pipe_redir(cmd))
		t = handle_file_name(cmd, t, last_type);
	if (t && t->str && t->str[0] == '\0')
		return (t->next);
	if (need_push_cmd(cmd))
		cmd = add_cmd(h);
	while (t && is_text_token(t))
	{
		if (!cmd->command && t->str && t->str[0] != '\0')
			cmd->command = ft_strdup(t->str);
		else
			ft_dstradd(&cmd->args, t->str);
		t = t->next;
	}
	return (t);
}
