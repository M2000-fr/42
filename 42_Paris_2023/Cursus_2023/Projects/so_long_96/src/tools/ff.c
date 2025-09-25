/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:09:23 by mechard           #+#    #+#             */
/*   Updated: 2024/07/01 14:02:06 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_floodfill(t_map *map, int x, int y)
{
	if (map->map[y][x] == 'C')
		(*map).nb_c++;
	if (map->map[y][x] == 'E')
		map->nb_e++;
	map->map[y][x] = 'F';
	if (map->map[y - 1][x] != '0' && map->map[y - 1][x] != 'F')
		ft_floodfill(map, x, y - 1);
	if (map->map[y + 1][x] != '0' && map->map[y + 1][x] != 'F')
		ft_floodfill(map, x, y + 1);
	if (map->map[y][x - 1] != '0' && map->map[y][x - 1] != 'F')
		ft_floodfill(map, x - 1, y);
	if (map->map[y][x + 1] != '0' && map->map[y][x + 1] != 'F')
		ft_floodfill(map, x + 1, y);
}

int	map_comp(t_game *game, char **map)
{
	t_map	check;

	map_init(&check, map);
	if (!check.map)
		return (0);
	ft_floodfill(&check, (*game).player_x / 64, (*game).player_y / 64);
	if (check.nb_e != 1)
		return (ft_dfree(check.map), 0);
	if (game->nb_collectibles != check.nb_c)
		return (ft_dfree(check.map), 0);
	ft_dfree(check.map);
	return (1);
}
