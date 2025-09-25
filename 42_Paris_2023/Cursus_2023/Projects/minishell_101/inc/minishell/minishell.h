/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:43:11 by mechard           #+#    #+#             */
/*   Updated: 2025/01/26 14:14:16 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <string.h>
# include <sys/ioctl.h>
# include <term.h>
# include <errno.h>
# include "builtins.h"
# include "executer.h"
# include "parser.h"
# include "other.h"
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

/* Global variables */
extern int	g_last_exit_code;

/* Structure */

typedef struct s_minishell
{
	int					flag;
	char				*path;
	char				*pwd;
	char				**shell;
	char				**env;
	char				**env_path;
	t_builtins			*builtins;
}						t_minishell;

/* Functions */

/*  Function returning a structure  */

t_minishell		*ft_init_minishell(char **env, t_builtins *builtins);
t_fds			*create_redir_fds(void);

/*  Function returning a void  */

void			ft_free_all(t_minishell *shell, t_prompt *prompt);
void			ft_mfree(t_minishell *shell);
void			ft_bfree(t_builtins *b);
void			active_user_input(void);
void			deactivate_active_input(void);
void			heredoc_signal(void);
void			free_and_exit(t_minishell	*s, t_cmd	*c, int stat, char **a);
void			exit_shell(int ret_code, int free_history);
void			ft_allfree(t_minishell	*shell, t_cmd	*cmd);

/*  Function returning a numeric value  */

int				is_directory(char	*str);
int				print_err(char	*msg_prefix, char	*msg, int ret);
int				print_err_quote_msg(char	*msg_prefix, char	*msg, int ret);
int				print_errno(char	*msg_prefix, int ret);
int				print_token_err(char *token, int error);
void			ft_puterr(char *s);

#endif
