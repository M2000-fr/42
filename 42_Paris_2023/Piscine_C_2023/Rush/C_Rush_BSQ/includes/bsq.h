/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 05:11:10 by ade-rese          #+#    #+#             */
/*   Updated: 2023/08/23 23:27:05 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_args
{
	int		nb_line;
	int		len;
	int		len_square;
	int		x;
	int		y;
	int		flags;
	char	obst;
	char	vide;
	char	remp;
}			t_args;

int			ft_is_new_line(char *str);
int			ft_count_line(char *map);
int			ft_count_len(char *map);
int			ft_check(char *str);
int			ft_toi(char *str);
int			ft_check_map(t_args *arg, char **map);
size_t		ft_strlen(char *s);

char		*ft_reader(int fd);
char		*ft_next(char *str);
char		*ft_get_line(char *str);
char		*ft_free_string(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_parse_rmp(char *str);
char		*ft_strmap(int fd, t_args *arg);
char		*ft_strcat(char *dest, char *src);
char		**ft_map_dd_init(char *map);
char		**ft_split_map(t_args *arg, int fd);
char		**ft_reso_bsq(t_args *arg, char **map);

void		ft_count(t_args *arg, char *map);
void		ft_putstr_fd(int std, char *str);
void		ft_puterror(t_args *arg, char **map, char *str);
void		ft_split_args(t_args *arg, char *str);

#endif
