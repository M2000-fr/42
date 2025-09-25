/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:12:24 by mechard           #+#    #+#             */
/*   Updated: 2025/01/23 14:37:07 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_variable(t_minishell	*shell, t_cmd	*cmd, int first, char	*var)
{
	if (!cmd->args)
	{
		ft_export_wa(shell);
		return (1);
	}
	if (!first)
	{
		if (!shell || !cmd || invalid_variable(var))
		{
			return (1);
		}
	}
	return (0);
}

char	**create_variable(char	*arg, size_t	*length)
{
	char	**variable;
	char	*str_to_equal;

	str_to_equal = ft_strchr(arg, '=');
	*length = str_to_equal - arg;
	variable = malloc(sizeof * variable * (2 + 1));
	variable[0] = ft_substr(arg, 0, str_to_equal - arg);
	variable[1] = ft_substr(str_to_equal, 1, ft_strlen(str_to_equal));
	variable[2] = NULL;
	return (variable);
}

int	update_env(t_minishell	*s, char	**v, size_t	l)
{
	if (update_var(s, v[0], l, v[1]) == 0)
	{
		handle_path(s, v[0]);
		return (0);
	}
	else if (add_variable(&s->env, v[0], l, v[1]) == 0)
	{
		handle_path(s, v[0]);
		return (0);
	}
	return (1);
}

int	ft_export(t_minishell	*shell, t_cmd	*cmd)
{
	char	**variable;
	size_t	length;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	if (check_variable(shell, cmd, 1, NULL))
		return (1);
	while (cmd->args[i])
	{
		if (check_variable(shell, cmd, 0, cmd->args[i]))
			return (1);
		else if (ft_strchr(cmd->args[i], '=') != NULL)
		{
			variable = create_variable(cmd->args[i], &length);
			ret = update_env(shell, variable, length);
			ft_dfree(variable);
		}
		i++;
	}
	return (ret);
}
