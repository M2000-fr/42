#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <string.h>
# include <unistd.h>
# include <sys/wait.h>

#endif

int err(char *str)
{
	while (*str) write(2, str++, 1);
	return (1);
}

int	cd(char **av, int i)
{
	return ( i != 2 ? err("error: cd: bad arguments\n") : ( chdir(av[1]) == -1 ? err("error: cd: cannot change directory "), err(av[1]), err("\n") : 0));
}

int	exec(char **env, char **av, int i)
{
	int fd[2], pid, status, has_pipe = av[i] && !strcmp(av[i], "|");

	if (has_pipe && pipe(fd) == -1) return (err("error: fatal\n"));
	if (!(pid = fork()) && !(av[i] = 0))
	{
		if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) || close(fd[1]))) return (err("error: fatal\n"));
		return (execve(*av, av, env), err("error: cannot execute "), err(*av), err("\n"));
	}
	return (waitpid(pid, &status, 0)), (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) || close(fd[1]))) ? err("error: fatal\n") : WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int ac, char **av, char **env)
{
	int status = 0, i = 0;

	while (ac > 1 && av[i] && av[++i])
	{
		av += i, i = 0;
		while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";")) i++;
		if (!strcmp(*av, "cd")) status=cd(av, i);
		else if (i) status=exec(env, av, i);
	}
	return (status);
}