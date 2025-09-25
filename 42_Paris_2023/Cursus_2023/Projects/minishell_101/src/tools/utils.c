/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:07:30 by mafritz           #+#    #+#             */
/*   Updated: 2025/01/26 15:19:49 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	alloc_if_needed(char	***dstr)
{
	if (!*dstr)
	{
		*dstr = malloc(sizeof(char *));
		if (!*dstr)
			return ;
		**dstr = NULL;
	}
}

int	not_in_quotes(t_status	*status)
{
	if (*status != STATUS_IN_QUOTES)
	{
		return (1);
	}
	return (0);
}

void	ft_puterr(char *s)
{
	int	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(STDERR_FILENO, s, len);
}

pid_t	ft_pid(int *pipe_fd, char **argv, char **envp)
{
	pid_t	pid;

	pid = 0;
	if (pipe(pipe_fd) == -1)
		return (perror("pipe"), 0);
	pid = fork();
	if (pid == -1)
		return (perror("fork"), 0);
	if (pid == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		execve("/bin/date", argv, envp);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	return (pid);
}

char	*get_current_time(void)
{
	t_gettime	time;
	char		*time_str;
	char		*time_tmp;

	time.envp = NULL;
	ft_memset(time.buffer, 0, sizeof(time.buffer));
	time.argv = ft_split("/bin/date +%H:%M:%S", ' ');
	time.pid = ft_pid(time.pipe_fd, time.argv, time.envp);
	close(time.pipe_fd[1]);
	wait(NULL);
	read(time.pipe_fd[0], time.buffer, sizeof(time.buffer) - 1);
	time.buffer[strcspn(time.buffer, "\n")] = 0;
	close(time.pipe_fd[0]);
	time_tmp = ft_strjoin("\001\033[34m\002", time.buffer);
	if (!time_tmp)
		return (ft_strdup("NULL"));
	time_str = ft_strjoin(time_tmp, "\001\033[0m}\002");
	free(time_tmp);
	ft_dfree(time.argv);
	return (time_str);
}
