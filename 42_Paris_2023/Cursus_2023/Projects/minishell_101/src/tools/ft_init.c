/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:30:32 by mechard           #+#    #+#             */
/*   Updated: 2025/01/26 16:46:59 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_shlvl(char **env)
{
	int		i;
	char	*shlvl;
	char	*tmp;

	i = 0;
	while (env && env[i])
	{
		if (!ft_strncmp(env[i], "SHLVL=", 6))
		{
			shlvl = ft_itoa(ft_atoi(env[i] + 6) + 1);
			tmp = ft_strjoin("SHLVL=", shlvl);
			free(shlvl);
			free(env[i]);
			env[i] = ft_strdup(tmp);
			free(tmp);
		}
		i++;
	}
	return (env);
}

t_minishell	*ft_init_minishell(char **env, t_builtins *builtins)
{
	t_minishell	*shell;

	shell = malloc(sizeof(t_minishell) * 1);
	if (!shell)
		return (NULL);
	shell->env_path = get_env_path(env);
	if (!shell->env_path)
		return (NULL);
	shell->env = ft_dstrdup(env);
	shell->env = ft_shlvl(shell->env);
	if (!shell->env)
		return (NULL);
	shell->path = NULL;
	shell->pwd = getcwd(NULL, 0);
	if (!shell->pwd)
		return (NULL);
	shell->builtins = builtins;
	shell->flag = 0;
	return (shell);
}

t_builtins	*ft_dbuiltins(void)
{
	t_builtins	*builtins;

	builtins = (t_builtins *)malloc(sizeof(t_builtins) * 1);
	if (!builtins)
		return (NULL);
	builtins->builtins = (t_b_list)
		malloc(sizeof(t_builtin) * 7);
	builtins->dic = (char **)malloc(sizeof(char *) * 7);
	if (!builtins->builtins || !builtins->dic)
		return (NULL);
	builtins->dic[0] = "echo";
	builtins->dic[1] = "cd";
	builtins->dic[2] = "pwd";
	builtins->dic[3] = "export";
	builtins->dic[4] = "unset";
	builtins->dic[5] = "env";
	builtins->dic[6] = "exit";
	builtins->builtins[0] = ft_echo;
	builtins->builtins[1] = ft_cd;
	builtins->builtins[2] = ft_pwd;
	builtins->builtins[3] = ft_export;
	builtins->builtins[4] = ft_unset;
	builtins->builtins[5] = ft_env;
	builtins->builtins[6] = ft_exit;
	return (builtins);
}
