/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:12:24 by mechard           #+#    #+#             */
/*   Updated: 2024/12/30 13:54:33 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strdigit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (ft_isdigit(str[i]) == 1)
		i++;
	return (i);
}

void	free_and_exit_shell(t_minishell	*s, t_cmd	*c, int stat)
{
	ft_allfree(s, c);
	exit_shell(stat, 1);
}

int	ft_exit(t_minishell *shell, t_cmd *cmd)
{
	int				i;
	long long int	res;

	ft_putstr_fd("exit\n", 1);
	if (ft_dstrlen(cmd->args) == 0)
		free_and_exit_shell(shell, cmd, 0);
	i = ft_strdigit(cmd->args[0]);
	res = ft_atoll(cmd->args[0]);
	if (cmd->args[0][i] != '\0' || res > LLONG_MAX || res < LLONG_MIN)
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmd->args[0], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		free_and_exit_shell(shell, cmd, 2);
	}
	if (ft_dstrlen(cmd->args) > 1)
		return (ft_putstr_fd("minishell: exit: too many arguments\n", 2), 1);
	free_and_exit_shell(shell, cmd, (unsigned char)res);
	return (0);
}
