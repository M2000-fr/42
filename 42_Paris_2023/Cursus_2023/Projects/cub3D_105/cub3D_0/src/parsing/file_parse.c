/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 08:28:52 by mechard           #+#    #+#             */
/*   Updated: 2025/04/04 08:28:52 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                              file_parse.c                                  */
/* ************************************************************************** */

#include "cub3d.h"

static int	read_header(int fd, t_cub *cub)
{
	int		header;
	char	*line;

	header = 0;
	line = get_next_line(fd);
	while (line && header < 6)
	{
		if (line[1] == '\n')
			free(line);
		else
		{
			if (parse_header_line(line, cub))
				return (free(line), 1);
			free(line);
			header++;
		}
		line = get_next_line(fd);
	}
	if (elements_order(line) == 6)
		free(line);
	else if (elements_order(line) < 6)
		return (ft_putendl_fd(HEADER_INCOMPL, 2), free(line), 1);
	else if (elements_order(line) == 7)
		return (ft_putendl_fd(FILE_FORMAT_IN, 2), free(line), 1);
	return (0);
}

static int	read_map(int fd, t_list **list)
{
	char	*line;
	t_list	*tmp;

	line = get_next_line(fd);
	if (line[1] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line)
	{
		if (ft_strlen(line) == 0)
			return (ft_lstclear(list, free), free(line), 1);
		tmp = ft_lstnew(ft_strdup(line));
		if (!tmp)
			return (ft_lstclear(list, free), free(line), 1);
		free(line);
		ft_lstadd_back(list, tmp);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	return (0);
}

int	parse_file(char *filename, t_cub *cub)
{
	int		fd;
	int		ret;
	t_list	*list;

	list = NULL;
	if (!is_valid_extension(filename))
		return (ft_putendl_fd(FILE_EXTENS_IN, 2), 1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd(FILE_CANT_OPEN, 2), 1);
	if (read_header(fd, cub))
		return (get_next_line(-1), close(fd), 1);
	if (read_map(fd, &list))
		return (get_next_line(-1), close(fd), 1);
	close(fd);
	if (!list)
		return (get_next_line(-1), ft_putendl_fd(MAP_NOT_FOUND, 2), 1);
	ret = convert_map_list(list, cub);
	get_next_line(-1);
	ft_lstclear(&list, free);
	return (ret);
}
