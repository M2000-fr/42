/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:12:24 by mechard           #+#    #+#             */
/*   Updated: 2024/12/30 13:53:50 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_eprintf(char	*str, int fd)
{
	size_t	i;

	i = 0;
	while (str[i])
		(write(fd, &str[i], 1), i++);
	return (0);
}

int	ft_minicmp(const char *s1, const char *s2)
{
	int	i;

	if (!ft_strncmp(s1, s2, 2))
		i = 2;
	else
		return (ft_strncmp(s1, s2, 2));
	while (s1[i] == s2[1])
		i++;
	if (s1[i] == s2[2])
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[2]);
}

void	print_str(char	**args, int arg, int flag)
{
	char	*str;

	if (flag == IS_VARIABLE)
	{
		str = cut_spaces(args[arg]);
	}
	else
	{
		str = ft_strdup(args[arg]);
	}
	ft_printf(str, 1);
	if (args[arg + 1])
	{
		ft_putchar_fd(' ', 1);
	}
	free(str);
}

int	ft_echo(t_minishell *shell, t_cmd	*cmd)
{
	int	arg;
	int	no_nl;

	if (!shell || !cmd)
		return (1);
	arg = -1;
	no_nl = 0;
	if (ft_dstrlen(cmd->args) >= 1)
	{
		while (cmd->args[++arg] && !ft_minicmp(cmd->args[arg], "-n"))
			no_nl = 1;
		while (cmd->args[arg])
		{
			print_str(cmd->args, arg, shell->flag);
			arg++;
		}
	}
	if (no_nl == 0)
		ft_putchar_fd('\n', 1);
	return (0);
}
