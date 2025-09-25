/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:42:06 by mechard           #+#    #+#             */
/*   Updated: 2024/12/30 14:05:59 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cfree(t_cmd *cmd)
{
	if (!cmd)
		return ;
	if (cmd->file_redir.outfile)
		free(cmd->file_redir.outfile);
	if (cmd->file_redir.infile)
		free(cmd->file_redir.infile);
	if (cmd->command)
		free(cmd->command);
	if (cmd->args)
		ft_dfree(cmd->args);
	if (cmd->next)
		(ft_cfree(cmd->next), cmd->next = NULL);
	free(cmd);
	cmd = NULL;
}

void	ft_mfree(t_minishell *shell)
{
	if (shell->env_path)
		ft_dfree(shell->env_path);
	if (shell->pwd)
		free(shell->pwd);
	if (shell->env)
		ft_dfree(shell->env);
	if (shell)
		free(shell);
}

void	ft_bfree(t_builtins *b)
{
	if (!b)
		return ;
	if (b->builtins)
		free(b->builtins);
	if (b->dic)
		free(b->dic);
	free(b);
}

void	ft_pfree(t_prompt *prompt)
{
	if (prompt->str)
		free(prompt->str);
}

void	ft_allfree(t_minishell	*shell, t_cmd	*cmd)
{
	t_cmd	*head;

	head = cmd;
	ft_bfree(shell->builtins);
	while (head && head->prev != NULL)
	{
		head = head->prev;
	}
	ft_cfree(head);
	ft_mfree(shell);
}
