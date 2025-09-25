/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:03:15 by maechard          #+#    #+#             */
/*   Updated: 2017/11/16 04:36:40 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strjoin_free(char *buff, char *tab)
{
	unsigned int	i;
	unsigned int	j;
	char			*ptr;

	i = 0;
	j = 0;
	if (buff)
		i = ft_strlen(buff);
	if (tab)
		j = ft_strlen(tab);
	ptr = (char *)malloc(sizeof(*ptr) * (i + j + 1));
	ft_memcpy(ptr, buff, i);
	ft_memcpy(ptr + i, tab, j);
	ptr[i + j] = '\0';
	free(buff);
	ft_bzero(tab, BUFF_SIZE + 1);
	return (ptr);
}

static int		ft_gnl_tmp(char **stock, char **line)
{
	char			*tmp;

	if ((tmp = ft_strchr(*stock, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(*stock);
		if (tmp + 1)
			tmp = ft_strdup(tmp + 1);
		else
			tmp = NULL;
		free(*stock);
		*stock = tmp;
		return (1);
	}
	return (0);
}

int				ft_gnl_read(char *buffer, char **stock, char **line)
{
	char	*tmp;

	if ((tmp = ft_strchr(buffer, '\n')))
	{
		*tmp = '\0';
		*line = ft_strjoin(*stock, buffer);
		if (tmp + 1)
			tmp = ft_strdup(tmp + 1);
		else
			tmp = NULL;
		free(*stock);
		free(buffer);
		*stock = tmp;
		return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char		*tab[BUFF_SIZE];
	char			*tmp;
	char			*buf;
	ssize_t			ret;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if (tab[fd] && ft_gnl_tmp(&tab[fd], line))
		return (1);
	buf = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (ft_gnl_read(buf, &tab[fd], line))
			return (1);
		tmp = ft_strjoin_free(tab[fd], buf);
		tab[fd] = ft_strdup(tmp);
		ft_memdel((void *)&tmp);
	}
	ft_memdel((void *)&buf);
	if ((tab[fd] == NULL || tab[fd][0] == '\0' || line == NULL) || ret == -1)
		return (ret == -1 ? -1 : 0);
	*line = ft_strdup(tab[fd]);
	ft_memdel((void *)&tab[fd]);
	return (1);
}
