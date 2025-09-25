/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:03:49 by ketrevis          #+#    #+#             */
/*   Updated: 2023/08/19 15:08:13 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*file_to_str(char *path)
{
	char	c;
	char	*file;
	int		size;
	int		i;
	int		fd;

	size = 0;
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, &c, 1) > 0)
		size++;
	file = malloc((size + 1) * sizeof(char));
	close(fd);
	fd = open(path, O_RDONLY);
	while (read(fd, &c, 1) > 0)
	{
		file[i] = c;
		i++;
	}
	file[i] = '\0';
	close(fd);
	return (file);
}

int	lines_nbr(char *str)
{
	int	lines;

	lines = 0;
	while (*str)
	{
		if (*str == '\n')
			lines++;
		str++;
	}
	return (lines);
}

int	line_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*new_line(char *str)
{
	char	*new;
	int		i;

	new = malloc((line_len(str) + 1) * sizeof(char));
	i = 0;
	while (str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	return (new);
}

char	**split_file(char *path)
{
	char	**strs;
	char	*str;
	int		i;
	int		j;

	str = file_to_str(path);
	if (str == 0)
		return (0);
	strs = malloc((lines_nbr(str) + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (*str)
	{
		strs[i] = new_line(str);
		i++;
		while (*str != '\n')
			str++;
		str++;
	}
	strs[i] = 0;
	return (strs);
}
