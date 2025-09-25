/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:03:15 by maechard          #+#    #+#             */
/*   Updated: 2017/11/16 04:36:40 by maechard        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"

static t_str		*creat_new_node(const int fd, char *buf, t_str **sstr)
{
	t_str			*new_node;

	if (!(new_node = (t_str *)malloc(sizeof(t_str))))
		return (NULL);
	new_node->fd = fd;
	if (!(new_node->str = ft_strdup(buf)))
		return (NULL);
	new_node->next = *sstr;
	*sstr = new_node;
	return (new_node);
}

static t_str		*check_fd_node(const int fd, t_str *sstr)
{
	while (sstr)
	{
		if (sstr->fd == fd)
			return (sstr);
		sstr = sstr->next;
	}
	return (NULL);
}

static int			check_node(const int fd, char *buff, t_str **sstr)
{
	t_str			*node;
	char			*tmp;

	node = check_fd_node(fd, *sstr);
	if (!node)
	{
		if (!(node = creat_new_node(fd, buff, sstr)))
			return (-1);
	}
	else
	{
		if (!(tmp = ft_strjoin(node->str, buff)))
			return (-1);
		free(node->str);
		node->str = tmp;
	}
	if (ft_strfind(node->str, '\n') != -1)
		return (1);
	return (0);
}

static char			*find_newline(const int fd, t_str *sstr)
{
	t_str			*node;
	char			*tmp;
	char			*ret_line;
	int				ret;

	ret_line = NULL;
	if (!(node = check_fd_node(fd, sstr)) || !node->str)
		return (NULL);
	if ((ret = ft_strfind(node->str, '\n')) != -1)
	{
		if (!(ret_line = ft_strsub(node->str, 0, ret)))
			return (NULL);
		if (!(tmp = ft_strdup(node->str + ret + 1)))
			return (NULL);
		free(node->str);
		node->str = tmp;
	}
	else
	{
		if (ft_strlen(node->str) != 0 && !(ret_line = ft_strdup(node->str)))
			return (NULL);
		ft_strdel(&node->str);
	}
	return (ret_line);
}

int					get_next_line(const int fd, char **line)
{
	static t_str	*sstr;
	char			buf[BUFF_SIZE + 1];
	int				ret;
	int				back;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		if ((back = check_node(fd, buf, &sstr)) == 1)
		{
			*line = find_newline(fd, sstr);
			return (1);
		}
		if (back == -1)
			return (-1);
	}
	if ((*line = find_newline(fd, sstr)) != NULL)
		return (1);
	return (0);
}
