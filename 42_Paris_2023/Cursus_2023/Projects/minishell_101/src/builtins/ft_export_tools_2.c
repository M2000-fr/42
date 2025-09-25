/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_tools_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafritz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:01:19 by mafritz           #+#    #+#             */
/*   Updated: 2025/01/22 12:01:24 by mafritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	update_var(t_minishell	*s, char	*var, size_t	l, char	*val)
{
	size_t	total_size;
	size_t	i;

	i = 0;
	while (s->env[i])
	{
		if (ft_strncmp(s->env[i], var, l) == 0 && s->env[i][l] == '=')
		{
			free(s->env[i]);
			total_size = l + ft_strlen(val) + 2;
			s->env[i] = malloc(total_size);
			if (!s->env[i])
				return (perror("malloc"), -1);
			append_variable_to_env(s->env[i], var, val);
			return (0);
		}
		i++;
	}
	return (1);
}

char	**create_new_env(char	***env, char	*new_var, size_t	env_size)
{
	char	**new_env;
	size_t	i;

	new_env = malloc((env_size + 2) * sizeof(char *));
	i = 0;
	if (!new_env)
		return (free(new_var), perror("malloc"), NULL);
	while (i < env_size)
	{
		new_env[i] = (*env)[i];
		i++;
	}
	new_env[env_size] = new_var;
	new_env[env_size + 1] = NULL;
	return (new_env);
}

int	add_variable(char ***env, char *var, size_t l, char *val)
{
	char	**new_env;
	char	*new_var;
	size_t	total_size;
	size_t	env_size;

	total_size = l + strlen(val) + 2;
	new_var = malloc(total_size);
	if (!new_var)
		return (1);
	append_variable_to_env(new_var, var, val);
	env_size = count_env(*env);
	new_env = create_new_env(env, new_var, env_size);
	if (!new_env)
		return (1);
	free(*env);
	*env = new_env;
	return (0);
}
