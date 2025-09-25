/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 13:00:20 by tarchen           #+#    #+#             */
/*   Updated: 2018/01/21 18:54:59 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <dirent.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <errno.h>
# include <pwd.h>
# include <time.h>
# include <grp.h>
# include "./get_next_line.h"
# include "../itoa/ft_itoa.h"
# define _FL_ (char *)__FUNCTION__, (int)__LINE__
# define STR_BASE "0123456789abcdefghijklmnopqrstuvwxyz"
# define STR_BASE_SIZE 36
# define STR_BASE_MAJ "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define STR_BASE_MAJ_SIZE 36
/*
** color letters
*/
# define C_BLACK 	"\033[30m"
# define C_RED 		"\033[31m"
# define C_GREEN	"\033[32m"
# define C_YELLOW	"\033[33m"
# define C_BLUE		"\033[34m"
# define C_MAGENTA	"\033[35m"
# define C_CYAN		"\033[36m"
# define C_WHITE	"\033[37m"
/*
** color background
*/
# define C_B_BLACK 	"\033[40m"
# define C_B_RED 		"\033[41m"
# define C_B_GREEN	"\033[42m"
# define C_B_YELLOW	"\033[43m"
# define C_B_BLUE		"\033[44m"
# define C_B_MAGENTA	"\033[45m"
# define C_B_CYAN		"\033[46m"
# define C_B_WHITE	"\033[47m"
/*
** default color reset
*/
# define C_RES		"\033[0m"

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
/*
** s_mam --> for memory allocation manager
*/
typedef struct		s_mam
{
	void			*ap;
	size_t			size;
	struct s_mam	*next;
	struct s_mam	*prev;
}					t_mam;
void				error(char *msg, int *code_error);
int					ft_atoi(const char *str);
long int			ft_atoi_lld(const char *str);
unsigned long int	ft_atoi_ulld(const char *str);
float				ft_atof(char *str);
double				ft_atod(char *str);
void				ft_bzero(void *s, int n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
char				*ft_itoa_base(int val, int base);
char				*ft_itoa_base_up(int val, int base);
char				*ft_itoa_base_u(unsigned int val, unsigned int base);
char				*ft_itoa_base_u_up(unsigned int val, int base);
char				*ft_itoa_base_u_lld(unsigned long long val, unsigned int base);
char				*ft_itoa_base_u_lld_up(unsigned long long val, int base);
char				*ft_itoa_base_u_ld(unsigned long val, unsigned int base);
char				*ft_itoa_base_u_ld_up(unsigned long val, int base);
char				*ft_itoa_base_lld(long long val, int base);
char				*ft_itoa_base_lld_up(long long val, int base);
char				*ft_itoa_base_ld(long val, int base);
char				*ft_itoa_base_ld_up(long val, int base);
void				*ft_memalloc(size_t size);
void				*ft_memalloca(size_t size);
void				*ft_memalloc_sp(size_t size);
void				*ft_memalloc_i(size_t size, int init);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
long				ft_power(int pow, int n);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_ll(long int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(char *src);
int					ft_strequ(char const *s1, char const *s2);
void				ft_strnjoin_f(char **dest, char *src, int n);
void				ft_strjoin_rf(char *src, char **dest);
void				ft_strjoin_f(char **dest, char *src);
void				ft_strjoin_ff(char **dest, char *src);
char				*ft_strjoin_rrff(char *dest, char *src);
char				*ft_strjoin_rrff_b(char *dest, char *src, size_t dest_len);
char				*ft_strjoin_rrff_bb(\
char *dest, char *src, size_t dest_len, size_t src_len);
void				ft_strjoin_ff_b(char **dest, char *src, size_t dest_len);
void				ft_strjoin_rff(char *src, char **dest);
void				ft_strjoin_rff_rb(char *src, char **dest, size_t dest_len);
char				*ft_strjoin(char *dest, char *src);
char				*ft_strbrut_single(char *str, int size);
size_t				ft_strlcat(char *dst, char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
char				*ft_strndup(const char *s, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(char *s1, char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				*try_malloc(size_t size, char *f, int l);
void				*try_alloca(size_t size, char *f, int l);
void				*try_malloc_i(size_t size, int init, char *f, int l);
void				*try_malloc_sp(size_t size, char *f, int l);
int					ft_strsfind(char *s, char *c);
int					ft_strfind(char *s, int c);
char				*ft_cat_char(char c, int nb_char);
int					ft_atoi_char(const char c);
void				ft_putdbl(double nbr, int i);
char				*ft_hextobin(char *hex_basic);
char				*ft_bintohex(char *bin_basic);
char				*ft_strrev(char *src);
void				ft_putnbr_u(unsigned int n);
int					ft_putnbr_lld_base_fd(long int nbr, int base, int fd);
int					ft_putnbr_base_fd(int nbr, int base, int fd);
int					ft_putnbr_lld_base(long int nbr, int base);
int					ft_putnbr_base(int nbr, int base);
char				*ft_strealloc(char *str, int new_size);
void				ft_strealloc_free(char *str, int new_size);
int					ft_nbrlen(int nbr);
int					ft_strnlen(const char *str, char c);
int					ft_strfind_ls_char(char *str, char *to_find);
char				*ft_strcut(char *str, int start, int end);
char				**ft_sort_params(int ac, char **av);
char				**ft_sort_nparams(int ac, char **av);
int					get_width_term(int option);
int					ft_print_tabstr(int size, char **tab, int endl);
int					ft_print_tabstr_fd(int size, char **tab, int endl, int fd);
int					ft_print_tabint(int size_tab, int *tab, int endl);
char				**ft_stradd(char **str, int *sizestr, char *new_elem);
void				ft_putchar_tab(char **tab);
int					ft_strfind_we(char *s, int c);
void				ft_strnjoin_f(char **dest, char *src, int n);
int					ft_strcut_f(char *str, int start, int end);
char				*ft_strchar(char c);
char				*ft_strinsert(char *dest, char *str, size_t n);
char				*ft_strjoin_ap(int nb_str, ...);
int					ft_putwchar(wchar_t chr);
char				*ft_wchartostr(wchar_t chr, int *size);
char				*ft_strbrut(char *str);
char				*ft_strbrut_blind(char *str, int size);


#endif
