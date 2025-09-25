/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:12:24 by mechard           #+#    #+#             */
/*   Updated: 2025/01/21 17:44:44 by mafritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	handle_path_unset(t_minishell	*s, char	**e, char	*v, size_t	l)
{
	if ((ft_strncmp(v, "PATH", l) == 0))
	{
		ft_dfree(s->env_path);
		s->env_path = get_env_path(e);
	}
}

char	**remove_idx(char	**arr, size_t idx)
{
	char	**new_arr;
	size_t	length;
	size_t	i;
	size_t	j;

	if (!arr)
		return (NULL);
	length = ft_dstrlen(arr);
	new_arr = malloc(length * sizeof(char *));
	if (!new_arr)
		return (NULL);
	i = 0;
	j = 0;
	while (i < length)
	{
		if (i != idx)
		{
			new_arr[j] = ft_strdup(arr[i]);
			j++;
		}
		i++;
	}
	new_arr[j] = NULL;
	return (new_arr);
}

size_t	adjust_env(t_minishell	*shell, size_t i)
{
	while (shell->env[i + 1])
	{
		shell->env[i] = shell->env[i + 1];
		i++;
	}
	return (i);
}

int	unset_aux(t_minishell	*shell, char	*var, size_t	len)
{
	char	**env;
	size_t	strncmp;
	size_t	i;

	i = 0;
	while (shell->env[i])
	{
		strncmp = ft_strncmp(shell->env[i], var, len);
		if (invalid_variable(var))
			return (EXIT_FAILURE);
		if (strncmp == 0 && shell->env[i][len] == '=')
		{
			env = remove_idx(shell->env, i);
			free(shell->env[i]);
			handle_path_unset(shell, env, var, len);
			i = adjust_env(shell, i);
			shell->env[i] = NULL;
			ft_dfree(env);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_unset(t_minishell *shell, t_cmd *cmd)
{
	char	*var;
	int		var_len;
	int		ret;
	int		i;

	if (!cmd->args)
		return (0);
	i = 0;
	ret = 0;
	while (cmd->args[i])
	{
		var = cmd->args[i];
		var_len = ft_strlen(var);
		ret = unset_aux(shell, var, var_len);
		i++;
	}
	return (ret);
}
