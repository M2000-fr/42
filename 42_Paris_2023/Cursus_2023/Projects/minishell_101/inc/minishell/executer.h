/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:01:28 by mafritz           #+#    #+#             */
/*   Updated: 2025/02/01 18:17:12 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

/* Includes */

# include "minishell.h"

/* Structures */

typedef struct s_cmd	t_cmd;

/**  Structures for the execution part  **/

typedef enum e_inredir_
{
	REDIR_IN_NONE = 0,
	REDIR_IN_FILE = 1,
}						t_inredir;

typedef enum e_outredir_
{
	REDIR_OUT_NONE = 0,
	REDIR_OUT_APPEND = 1,
	REDIR_OUT_OVERWRITE = 2,
}						t_outredir;

typedef struct s_redir
{
	t_inredir			intype;
	t_outredir			outtype;
	char				*infile;
	char				*outfile;
}						t_redir;

typedef enum e_pipe_
{
	PIPE_NONE = -1,
	PIPE_IN = 0,
	PIPE_OUT = 1
}						t_pipe;

typedef struct s_cmd
{
	char				*command;
	char				**args;
	t_redir				file_redir;
	t_pipe				pipe_redir;
	struct s_cmd		*prev;
	struct s_cmd		*next;
}						t_cmd;

typedef struct s_fds
{
	char				*infile;
	char				*outfile;
	int					fd_in;
	int					fd_out;
	int					*pipe_fd;
	int					in_backup;
	int					out_backup;
	pid_t				pid;
}						t_fds;

typedef struct s_fds_list
{
	struct s_fds_list	*next;
	struct s_fds_list	*prev;
	t_fds				*fds;
	t_cmd				*cmd;
}						t_fds_list;

/* Functions */

/*  Function returning a structure  */

t_fds_list		*push_to_fds_list(t_fds_list **head, t_fds *fds, t_cmd *cmd);
t_cmd			*check_cmd(t_cmd *cmd);

/*  Function returning a numeric value  */

int				try_open_outfile(t_cmd *cmd, char *outfile, t_fds *fds);
int				try_execute_builtin(t_minishell *s, t_cmd *c, t_builtins *b);
int				execute_local_bin(t_minishell *shell, t_cmd *cmd, char **args);
int				execute_sys_bin(t_minishell *shell, t_cmd *cmd, char **args);
int				open_file_redir(t_cmd *cmd, t_fds *fds);
int				open_pipe_redir(t_cmd *cmd, t_fds *fds, t_fds *prev_fds);
int				wait_for_children(int last_pid);
int				basic_precheck(t_minishell *shell, t_cmd	*cmd);
int				ft_exec(t_minishell *shell, t_cmd	*exec);
int				init_pipe(t_cmd	*cmd, t_fds *fds);
int				init_file_redir(t_cmd *cmd, t_fds	*fds);
int				reset_file_redir(t_fds *fds);

/*  Function returning a character, a string or an array  */

char			**generate_argv_from_cmd(t_cmd *cmd);

/*  Function returning a void  */

void		 	init_fds(t_fds *fds);
void			close_fds_list(t_fds_list *head);
void			reset_free_exit(t_fds_list *l, t_minishell *s, t_cmd *c);
void			init_pipe_redir(t_cmd *cmd, t_fds *fds);
void			reset_and_close_fds_list(t_fds_list *head);
void			reset_fds_list(t_fds_list *head);
void			close_fds_list(t_fds_list *head);
void			copy_cmd(t_cmd *dest, t_cmd *orig);
#endif
