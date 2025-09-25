/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:23:35 by mechard           #+#    #+#             */
/*   Updated: 2024/03/06 12:48:24 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>

# ifndef PATH
#  define PATH "PATH="
# endif

# ifndef PATH_SIZE
#  define PATH_SIZE 5
# endif

# ifndef PATH_ENV_SEPARATOR
#  define PATH_ENV_SEPARATOR ':'
# endif

typedef struct s_cmd
{
	char	*path;
	char	**cmd;
}			t_cmd;

typedef struct s_pipex
{
	char	*outfile;
	char	*infile;
	char	**path;
	char	**env;
	int		prev_pipe;
	t_cmd	cmd;
	int		pipefd[2];
	int		pids[1024];
	int		size;
	int		j;
}			t_pipex;

int			open_fd(t_pipex *pipex, int i);
int			wait_pids(int *pids);
int			ft_read_user(char *av1, char *av2);
int			pipex(int ac, char **av, char **env);

char		*find_path(char **possible_path, char *cmd);
char		*build_cmd(char *path, char *cmd);
char		*ft_reader(char *av2, char *res);
char		**get_env_path(char **env);
char		**build_argv(t_pipex *pipex);

void		child_process(t_pipex *pipex, char *cmd, int i);
void		ft_init(t_pipex *pipex, int ac, char **av, char **env);
void		init_pipex_no_hd(t_pipex *pipex, int ac, char **av, char **env);
void		init_pipex_w_hd(t_pipex *pipex, int ac, char **av, char **env);
void		free_dstr(char **dstr);

#endif