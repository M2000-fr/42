/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:27:59 by mechard           #+#    #+#             */
/*   Updated: 2025/01/26 14:12:45 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* Library */

# include "get_next_line.h"
# include "ft_printf.h"
# include "pipex.h"
# include "so_long.h"
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* Structure variable */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* Function returning a numeric variable */

size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_nbrlen(long n, int base);
size_t				ft_atos(const char *str);
size_t				ft_strlen(const char *s);
long long int		ft_atoll(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(char *s1, char *s2);
int					ft_memcmp(void *s1, void *s2, size_t n);
int					count_word(const char *str, char c);
int					ft_atoi(const char *str);
int					ft_lstsize(t_list *lst);
int					ft_dstrlen(char **cmd);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/* Function returning a char variable */

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_dstrscpy(char **dstr, int start, int sub, int flag);
char				*ft_strncpy(char *dest, const char *src, int end);
char				*ft_strscpy(char *dest, const char *src, int start);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strtrim(char const *s1, char const *student);
char				*ft_dstrncpy(char **dstr, int sub, int flag);
char				*ft_dstrcpy(char **dstr, int sub, int flag);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strcat(char *dest, char *src);
char				**ft_split(const char *s, char c);
char				*ft_dstrjoin_wsp(char **dstr);
char				*ft_strrchr(char *s, int c);
char				*ft_strdup(const char *src);
char				*ft_strndup(const char	*str,	size_t n);
char				*ft_strchr(char *s, int c);
char				*ft_itoa(int n);
char				**ft_dstrdup(char **str);

/*Function returning a custom variable*/

t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);

/*Function returning a void variable*/
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_putdstr_fd(char **str, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar_libft(char c);
void				ft_putstr_fd(char *s, int fd);
void				ft_putstr_libft(char *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr_libft(int n);
void				ft_bzero(void *s, size_t n);
void				ft_memdel(void **ap);
void				ft_dstradd(char	***dstr, char	*str);
void				*ft_memset(void *s, int c, size_t len);
void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_memchr(void *s, int c, size_t n);
void				*ft_memmove(void *dst, void *src, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);

/*Function in development*/

#endif
