/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 08:25:20 by mechard           #+#    #+#             */
/*   Updated: 2025/04/04 08:25:20 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_map_chars(char *line, int *start_count)
{
	size_t	i;
	size_t	max;

	i = 0;
	max = ft_strlen(line) - 1;
	if (line[max] == '\n')
		line[max - 1] = '\0';
	while (line[i] && i < max)
	{
		if (line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W'
			&& line[i] != ' ')
			return (ft_putendl_fd(MAP_INVALID, 2), 0);
		if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
			(*start_count)++;
		i++;
	}
	return (1);
}

static int	checking(char **map, int i, int j, int rows)
{
	int	len;

	len = ft_strlen(map[i]);
	if (map[i][j] == '0' || map[i][j] == 'N'
		|| map[i][j] == 'S' || map[i][j] == 'E'
		|| map[i][j] == 'W')
		if ((i == 0 || i == rows - 1 || j == 0 || j == len - 1)
			|| (j >= (int)ft_strlen(map[i - 1]) || map[i - 1][j] == ' ')
			|| (j >= (int)ft_strlen(map[i + 1]) || map[i + 1][j] == ' ')
			|| (map[i][j - 1] == ' ' || map[i][j + 1] == ' '))
			return (1);
	return (0);
}

static int	check_surounded(char **map, int rows)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while ((size_t)j < ft_strlen(map[i]))
		{
			if (checking(map, i, j, rows))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_map(char **map)
{
	size_t	i;
	size_t	rows;
	int		start_count;

	start_count = 0;
	rows = 0;
	i = 0;
	if (!map)
		return (0);
	while (map[rows])
	{
		rows++;
		while (i < rows)
			if (!check_map_chars(map[i++], &start_count))
				return (0);
	}
	if (start_count != 1)
		return (ft_putendl_fd(INVALID_STA_PO, 2), 0);
	if (!check_surounded(map, rows))
		return (ft_putendl_fd(MAP_NOT_SURROU, 2), 0);
	return (1);
}
