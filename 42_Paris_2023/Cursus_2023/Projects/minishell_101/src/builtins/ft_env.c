/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:12:24 by mechard           #+#    #+#             */
/*   Updated: 2024/12/30 13:54:17 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_minishell *shell, t_cmd *cmd)
{
	int	arg_len;
	int	cmd_len;
	int	i;

	if (!shell->env)
	{
		return (1);
	}
	arg_len = ft_dstrlen(cmd->args);
	cmd_len = ft_strlen(cmd->command);
	i = 0;
	if (arg_len == 0 && !ft_strncmp(cmd->command, "env", cmd_len))
	{
		while (shell->env[i])
			(printf("%s\n", shell->env[i]), i++);
	}
	return (0);
}
