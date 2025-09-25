/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:43:08 by mechard           #+#    #+#             */
/*   Updated: 2025/01/26 14:34:11 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_cmd_status_and_execute(t_minishell *shell, char *str)
{
	t_cmd	*cmd;
	int		status;

	status = 0;
	cmd = NULL;
	cmd = ft_parser(shell, str);
	if (cmd)
	{
		status = check_and_execute(shell, cmd);
		ft_cfree(cmd);
	}
	return (status);
}

int	ft_minishell(t_minishell *shell, t_builtins *builtins)
{
	t_prompt	prompt;
	int			status;
	char		*str;

	g_last_exit_code = 0;
	status = 0;
	while (42)
	{
		active_user_input();
		shell->pwd = ft_maj_pwd(shell);
		str = ft_prompt();
		prompt.str = custom_readline(str);
		(free(str), deactivate_active_input());
		if (ctrl_d_handling(prompt.str, "exit"))
		{
			ft_pfree(&prompt);
			break ;
		}
		status = set_cmd_status_and_execute(shell, prompt.str);
		if (status != -1)
			g_last_exit_code = status;
		ft_pfree(&prompt);
	}
	return (ft_mfree(shell), ft_bfree(builtins), g_last_exit_code);
}

int	main(int ac, char **av, char **env)
{
	t_minishell	*shell;
	t_builtins	*builtins;
	int			exit;

	(void)shell;
	shell = NULL;
	if (!env[0])
	{
		return (ft_putstr_fd(NO_ENV, 2), 0);
	}
	if (ac != 1 || av[1])
		return (ft_putstr_fd(ERROR_ARGUMENTS, 2), 0);
	builtins = ft_dbuiltins();
	shell = ft_init_minishell(env, builtins);
	exit = ft_minishell(shell, builtins);
	exit_shell(exit, 1);
	return (0);
}
