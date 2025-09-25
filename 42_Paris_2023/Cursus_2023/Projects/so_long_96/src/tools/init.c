/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:49:47 by mechard           #+#    #+#             */
/*   Updated: 2024/07/01 15:31:00 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**recup_map(char *str)
{
	int		i;
	int		fd;
	int		y;
	char	*tmp;
	char	**res;

	i = 0;
	y = count_line(str);
	if (y == 0)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * y);
	if (!res)
		return (NULL);
	fd = open(str, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		res[i++] = tmp;
		tmp = get_next_line(fd);
	}
	res[i++] = tmp;
	get_next_line(-1);
	close(fd);
	return (res);
}

void	ft_init_null(t_game *game)
{
	game->i = 0;
	game->step = 0;
	game->exit = 0;
	game->col = NULL;
	game->exi = NULL;
	game->roc = NULL;
	game->sol = NULL;
	game->pla = NULL;
	game->canva = NULL;
	game->win_ptr = NULL;
	game->keycode_prev = 0;
	game->collectibles = 0;
	game->nb_collectibles = 0;
}

int	ft_tablen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i + 1);
}

char	**ft_dstrdup(char **str)
{
	int		i;
	char	**res;

	i = 0;
	res = (char **)malloc(sizeof(char *) * ft_tablen(str));
	if (!res)
		return (NULL);
	while (str && str[i])
	{
		res[i] = ft_strdup(str[i]);
		if (!res[i])
			return (NULL);
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	map_init(t_map *map, char **str)
{
	map->map = ft_dstrdup(str);
	map->player_x = 0;
	map->player_y = 0;
	map->x = 0;
	map->y = 0;
	map->i = 0;
	map->width = 0;
	map->len = 0;
	map->nb_p = 0;
	map->nb_c = 0;
	map->nb_e = 0;
}
