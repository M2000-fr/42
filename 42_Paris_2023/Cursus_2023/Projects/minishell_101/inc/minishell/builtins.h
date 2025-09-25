/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:59:59 by mafritz           #+#    #+#             */
/*   Updated: 2025/01/26 13:28:10 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

/* Structures */

typedef struct s_minishell	t_minishell;
typedef struct s_cmd		t_cmd;
typedef struct s_fds		t_fds;

/**  Structures for builtins  **/

typedef int					(*t_builtin)(t_minishell *, t_cmd *);

typedef t_builtin			*t_b_list;

typedef struct s_builtins
{
	t_b_list				builtins;
	char					**dic;
}							t_builtins;

/* Functions */

/*  Function returning a structure  */

t_builtins		*ft_dbuiltins(void);

/*  Function returning a numeric value  */

size_t			count_env(char **env);
int				add_variable(char ***env, char *var, size_t l, char *val);
int				invalid_variable(char	*var);
int				update_var(t_minishell	*s, char	*v, size_t	l, char	*vl);
int				get_length(char	*oldpwd, char	*pwd);
int				ft_cd_error(char *str);
int				ft_retrievebi(char *shell, t_builtins *builtins);
int				ft_builtins(t_minishell *s, t_cmd	*c, t_builtins *b);
int				ft_export(t_minishell *shell, t_cmd	*cmd);
int				ft_unset(t_minishell *shell, t_cmd	*cmd);
int				ft_echo(t_minishell *shell, t_cmd	*cmd);
int				ft_exit(t_minishell *shell, t_cmd	*cmd);
int				ft_env(t_minishell *shell, t_cmd	*cmd);
int				ft_pwd(t_minishell *shell, t_cmd	*cmd);
int				ft_cd(t_minishell *shell, t_cmd	*cmd);
int				invalid_variable(char	*var);

/*  Function returning a character, a string or an array  */

char			**create_new_env(char ***env, char *new_v, size_t size);
char			*retrieve_target(t_minishell *s, t_cmd *c, char *old);
char			*get_oldpwd(char **env);
char			*ft_join_path(char	**dstr);
char			*ft_maj_pwd(t_minishell *shell);
char			*get_pwd(char **env);
char			*cut_spaces(char	*str);
char			**get_usr(char **env);

/*  Function returning a void  */

void			free_var_val(char	*var, char	*val);
void			destroy_redir_fds(t_fds	*fds);
void			close_pipe_fds(t_fds	*fds);
void			close_redir_fds(t_fds	*fds);
void			append_variable_to_env(char	*e, char	*v, char	*val);
void			handle_path(t_minishell	*s, char	*v);
void			ft_export_wa(t_minishell *shell);

#endif
