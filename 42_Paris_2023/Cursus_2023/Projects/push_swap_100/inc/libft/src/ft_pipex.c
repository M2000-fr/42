/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:38:53 by mechard           #+#    #+#             */
/*   Updated: 2024/03/06 12:51:11 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_dstr(char **dstr)
{
	int	i;

	i = 0;
	while (dstr && dstr[i])
		free(dstr[i++]);
	free(dstr);
}

char	**get_env_path(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
	{
		if (!ft_strncmp(env[i], PATH, PATH_SIZE))
			return (ft_split(&env[i][5], PATH_ENV_SEPARATOR));
		i++;
	}
	return (NULL);
}

int	wait_pids(int *pids)
{
	int	i;
	int	stat;

	i = 0;
	while (pids[i] != -1)
		waitpid(pids[i++], &stat, 0);
	if (WIFEXITED(stat))
		return (WEXITSTATUS(stat));
	return (1);
}

int	pipex(int ac, char **av, char **env)
{
	t_pipex	pipex;
	int		i;

	if (ac < 5 || ac > 1024)
		return (ft_printf("Il faut entre 5 et 1024 arguments\n"), EXIT_FAILURE);
	ft_init(&pipex, ac, av, env);
	i = 0;
	while (i < (ac - (1 + pipex.j)))
	{
		if (i < (ac - (2 + pipex.j)))
			pipe(pipex.pipefd);
		pipex.pids[i] = fork();
		if (pipex.pids[i] == 0)
			child_process(&pipex, av[pipex.j + i], i);
		if (pipex.prev_pipe != -1)
			close(pipex.prev_pipe);
		pipex.prev_pipe = pipex.pipefd[0];
		close(pipex.pipefd[1]);
		i++;
	}
	close(pipex.pipefd[0]);
	close(pipex.prev_pipe);
	free_dstr(pipex.path);
	pipex.pids[i] = -1;
	return (wait_pids(pipex.pids));
}
