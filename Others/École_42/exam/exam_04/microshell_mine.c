#ifndef MICROSHRLL_H
# define MICROSHELL_H

# include <unistd.h>
# include <string.h>
# include <sys/wait.h>

#endif

int err(char *str)
{
    while (*str) write(2, str++, 1);
    return (1);
}

int cd(char **argv, int i)
{
    return (i != 2 ? err("error: cd: bad arguments\n") : (chdir(argv[1]) == -1 ? err("error: cd: cannot change directory to "), err(argv[1]), err("\n") : 0));
}

int exec(char **argv, char **envp, int i)
{
    int fd[2], status, pid, has_pipe = argv[i] && !strcmp(argv[i], "|");

    if (has_pipe && pipe(fd) == -1) return err("error: fatal\n");
    if (!(pid = fork()) && !(argv[i] = 0))
    {
        if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) || close(fd[1]))) return err("error: fatal\n");
        return execve(*argv, argv, envp), err("error: cannot execute "), err(*argv), err("\n");
    }
    return (waitpid(pid, &status, 0), ((has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) || close(fd[1])))) ? err("error: fatal\n") : WIFEXITED(status) && WEXITSTATUS(status));
}

int main(int argc, char **argv, char **envp)
{
    int i = 0, status = 0;
    while (argc > 1 && argv[i] && argv[++i])
    {
        argv += i; i = 0;
        while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";")) i++;
        if (!strcmp(*argv, "cd")) status = cd(argv, i);
        else if (i) status = exec(argv, envp, i);
    }
    return status;
}
