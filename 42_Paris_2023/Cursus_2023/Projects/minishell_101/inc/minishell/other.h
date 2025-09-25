/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:48:52 by mechard           #+#    #+#             */
/*   Updated: 2025/01/26 12:53:38 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHER_H
# define OTHER_H

/* Includes */

# include <readline/history.h>
# include <readline/readline.h>

/* Defines */

/** Defines for errors in minishell **/

# ifndef ERROR_ARGUMENTS
#  define ERROR_ARGUMENTS "minishell must not be launched with arguments !\n"
# endif

# define NO_ENV "FATAL : env doesn't exist ! Emergency exit\n"
# ifndef ERROR_CLEARPROMPT
#  define ERROR_CLEARPROMPT "An error has occurred while retrieving the clear \
command.\n"
# endif

/** Define for the prompt **/

# ifndef PROMPT
#  define PROMPT "minishell : -> "
# endif

/** Defines for builtins **/

# ifndef PWD
#  define PWD "PWD="
# endif

# ifndef HOME
#  define HOME "HOME="
# endif

# ifndef SIZE
#  define SIZE 5
# endif

# ifndef ENV_SEPARATOR
#  define ENV_SEPARATOR '/'
# endif
# ifndef HEREDOC_NAME
#  define HEREDOC_NAME "/tmp/.minishell_heredoc_"
# endif
# ifndef SYNTAX_ERROR
#  define SYNTAX_ERROR "syntax error near unexpected token"
# endif
# ifndef INVALID_CHARACTER
#  define INVALID_CHARACTER "contains invalid characters after '='"
# endif 
# ifndef IS_DIR
#  define IS_DIR "Is a directory"
# endif 
# define CMD_NOT_FOUND 127

# define EMPTY_CMD 126
# define EMPTY_PROMPT 1
# define EMPTY_STR 2
# define IS_VARIABLE 3
# define INVALID_PERMISSIONS 4

/* Structures */

typedef struct s_minishell	t_minishell;

/**  Structures for the prompt  **/

typedef struct s_gettime
{
	int					pipe_fd[2];
	char				**envp;
	char				**argv;
	pid_t				pid;
	char				buffer[64];
}						t_gettime;

typedef struct s_prompt
{
	char				*str;
	char				*prompt;
}						t_prompt;

/* Functions */

/*  Function returning a character, a string or an array  */
char			*custom_readline(char *prompt);
char			*get_current_time(void);
char			*ft_prompt(void);
/*  Function returning a void  */

void			ft_pfree(t_prompt *prompt);

#endif