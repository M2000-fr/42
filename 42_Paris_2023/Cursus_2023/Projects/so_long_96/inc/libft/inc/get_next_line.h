/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:29:16 by mechard           #+#    #+#             */
/*   Updated: 2024/04/23 17:06:40 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "libft.h"
# include <stdlib.h>
# include <limits.h>

char	*ft_next_line(char *str);
char	*get_next_line(int fd);
char	*ft_get_line(char *str);
char	*ft_free_string(char *str);
char	*ft_strjoin_gnl(char *s1, const char *s2);
size_t	ft_strlen_gnl(char *s);
int		ft_new_line(char *str);

#endif