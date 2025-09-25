/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:37:22 by mechard           #+#    #+#             */
/*   Updated: 2024/07/08 13:16:37 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	verif_name(char *str)
{
	while (*str)
		str++;
	str -= 4;
	if (ft_strncmp(str, ".ber", 4) == 0)
		return (0);
	return (ft_printf(INVALID_NAME), 1);
}

int	so_long(int ac, char **av)
{
	char	**map;
	t_game	*game;

	map = NULL;
	if (ac != 2)
		return (ft_printf("Il n'y a pas le bon nombre d'arguments\n"), 0);
	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	ft_init_null(game);
	map = verif_map(av[1], map, game);
	if (!map)
		return (free(game), 0);
	game->map = map;
	open_windows(game);
	return (0);
}
