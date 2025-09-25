/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:40:49 by tarchen           #+#    #+#             */
/*   Updated: 2018/01/14 19:10:08 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# define BUFF_SIZE 1

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct		s_str
{
	char			*str;
	int				fd;
	struct s_str	*next;
}					t_str;
int					get_next_line(const int fd, char **line);
int					gnl_stdout(char **line);

#endif
