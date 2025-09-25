/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:25:38 by mechard           #+#    #+#             */
/*   Updated: 2024/07/08 13:18:04 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_line(char *str)
{
	char	*tmp;
	int		fd;
	int		i;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0 || fd > 1024 || read(fd, 0, 0) < 0)
		return (0);
	tmp = ft_calloc(1, sizeof(char));
	if (!tmp)
		return (0);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	free(tmp);
	get_next_line(-1);
	close(fd);
	return (i);
}

int	check_cara(char **map, char *cara, t_map *coor)
{
	while (map && map[coor->y])
	{
		coor->x = 0;
		while (map[coor->y][coor->x] != '\n' && map[coor->y][coor->x])
		{
			coor->i = 0;
			while (map[coor->y][coor->x] != cara[coor->i] && cara[coor->i])
				coor->i++;
			if (map[coor->y][coor->x] == 'P')
				ft_coor(coor->x, coor->y, coor);
			else if (map[coor->y][coor->x] == 'E')
				coor->nb_e++;
			else if (map[coor->y][coor->x] == 'C')
				coor->nb_c++;
			if (map[coor->y][coor->x] == '\0' || coor->x > (coor->len - 1))
				return (ft_printf(INVALID_MAP), 1);
			if (!cara[coor->i])
				return (ft_printf(INVALID_CARA), 1);
			coor->x++;
		}
		coor->y++;
	}
	coor->width = coor->y;
	return (0);
}

int	verif_cara(char **map, t_map *coor)
{
	char	*cara;

	cara = VALID_CARA;
	if (check_cara(map, cara, coor) == 1)
		return (1);
	if (coor->nb_c < 1)
		return (ft_printf(INVALID_COL), 1);
	if (coor->nb_p != 1 || coor->nb_e != 1)
		return (ft_printf(INVALID_NB), 1);
	return (0);
}

int	verif_border(char **map, t_map *coor)
{
	int	i;

	i = 0;
	while (map[0][i] && map[0][i] != '\n')
	{
		if (map[0][i] != '0' || map[coor->width - 1][i] != '0')
			return (ft_printf(INVALID_MAP), 1);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '0' || map[i][coor->len - 1] != '0')
			return (ft_printf(INVALID_MAP), 1);
		i++;
	}
	return (0);
}

char	**verif_map(char *str, char **map, t_game *game)
{
	t_map	coor;

	coor.y = 0;
	coor.nb_p = 0;
	coor.nb_c = 0;
	coor.nb_e = 0;
	map = recup_map(str);
	if (!map)
		return (ft_printf(ERROR_REC), NULL);
	coor.len = ft_strlen(map[0]) - 1;
	if (verif_name(str) == 1 || verif_cara(map, &coor) == 1 || verif_border(map,
			&coor))
		return (ft_dfree(map), NULL);
	game->len = coor.len;
	game->width = coor.width;
	game->nb_collectibles = coor.nb_c;
	game->player_x = coor.player_x * 64;
	game->player_y = coor.player_y * 64;
	if (!map_comp(game, map))
		return (ft_printf(INVALID_ROAD), ft_dfree(map), NULL);
	return (map);
}
