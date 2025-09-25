/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:48:00 by mechard           #+#    #+#             */
/*   Updated: 2025/01/26 13:28:29 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/* Structures */

typedef struct s_minishell	t_minishell;

/**  Structures for the tokenizer  **/

typedef enum e_token_
{
	TOK_TEXT,
	TOK_SQUOTE_TEXT,
	TOK_DQUOTE_TEXT,
	TOK_SPACE,
	TOK_PIPE,
	TOK_HEREDOC,
	TOK_APPEND,
	TOK_OVERWRITE,
	TOK_INPUT,
	TOK_INVALID,
	TOK_END
}							t_v_token;

typedef enum e_token_status_
{
	STATUS_IN_QUOTES,
	STATUS_IN_DQUOTES,
	STATUS_ERR,
	STATUS_OK,
}							t_status;

typedef struct s_token
{
	t_v_token				type;
	char					*str;
	struct s_token			*next;
}							t_token;

typedef struct s_token_line
{
	t_token					*token_list;
	t_status				status;
}							t_token_line;

typedef struct s_interpolator
{
	t_minishell				*shell;
	char					**str;
	char					*res;
	int						*res_i;
	int						*len;
}							t_interpolator;

/* Functions */

/*  Function returning a structure  */

t_token_line		ft_tokenizer(t_minishell *shell, char *raw_str);
t_token_line		init_token_line(void);
t_v_token			retrieve_token_type(char *raw_str, int i);
t_status			init_quote_status(void);
t_status			update_status(char *raw_str, int i, t_token_line *l);
t_token				*ft_parse_heredoc(t_minishell *s, t_cmd **c, t_token *t);
t_token				*ft_parse_text(t_cmd **h, t_token *t, t_v_token last_type);
t_token				*ft_parse_file_redir(t_cmd **cmd_head, t_token *token);
t_token				*ft_parse_pipe(t_cmd **cmd_head, t_token *token);
t_cmd				*get_last_cmd(t_cmd *head);
t_cmd				*add_cmd(t_cmd **head);
t_cmd				*ft_parser(t_minishell *shell, char *raw_user_input);

/*  Function returning a numeric value  */

int					not_in_quotes(t_status *status);
int					ft_token_redir(char *raw_str, int i);
int					is_redir_char(char c);
int					ctrl_d_handling(char *str, char *message);
int					check_and_execute(t_minishell *shell, t_cmd *cmd);
int					check_cmd_status(t_minishell *shell, t_cmd *cmd);
int					has_file_redir(t_cmd *cmd);
int					is_text_token(t_token *token);
int					has_pipe_redir(t_cmd *cmd);
int					no_str_found(t_token *token);
int					is_invalid_token(t_token_line *l, t_v_token type);
int					update_quote_status(char c, char **s, t_status *quote);
int					is_quote(char c);
int					skip_spaces(char	*str, int i);
int					is_text_token(t_token	*token);
int					get_sep_len(t_v_token type);
int					ft_isspace(char c);
int					compute_var_name_length(char	*str);
int					extract_next_token(char	*str, t_token_line	*l, int i);

/*  Function returning a character, a string or an array  */

char				*extract_variable_value(t_minishell *s, char *str, int len);
char				*add_str_to_buff(char *buff, int *i, int *len, char *str);
char				*add_char_to_buff(char *buffer, int *i, int *len, char c);
char				*reallocate_buffer(char *buffer, int *size, int new_size);
char				*allocate_empty_string(int size);
char				*find_equal_sign(char *arg);
char				*ft_upoldpwd(t_minishell *shell, char *pwd);
char				*get_env_value(t_minishell *shell, const char *var_name);
char				*add_var_value(t_interpolator *ctx);
char				*get_file_name(void);
char				*extract_invalid_token(char *str, int i);
char				*interpolate_variables(t_minishell *s, char *str, int q);
char				*get_delim(char *delim);
char				*get_file_name(void);

/*  Function returning a void  */

void				ft_dstradd(char ***dstr, char *str);
void				check_status(t_token_line *tokenized_line);
void				push_token(t_token_line *line, char *token, int type);
void				ft_cfree(t_cmd *cmd);
void				print_invalid_token_msg(char *str, int i);

#endif