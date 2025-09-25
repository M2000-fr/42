/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:04:44 by mechard           #+#    #+#             */
/*   Updated: 2025/04/04 02:41:38 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_finish(t_game *game)
{
	if (game->map[game->player_y / 64][game->player_x / 64] == 'E'
		&& game->player_y % 64 == 0 && game->player_x % 64 == 0
		&& game->collectibles == game->nb_collectibles)
	{
		ft_printf(SUCCESS, game->step);
		close_window(game);
	}
	if (game->map[game->player_y / 64][game->player_x / 64] == 'E'
		&& game->player_y % 64 == 0 && game->player_x % 64 == 0
		&& game->collectibles < game->nb_collectibles)
	{
		if (game->nb_collectibles - game->collectibles == 1)
			ft_printf(NOT_SUCCESS, game->nb_collectibles - game->collectibles);
		else
			ft_printf(NOTS_SUCCESS, game->nb_collectibles - game->collectibles);
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == XK_Control_L)
		game->keycode_prev = 1;
	if (keycode == XK_Escape)
		close_window(game);
	if ((keycode == XK_d || keycode == XK_c) && game->keycode_prev == 1)
		close_window(game);
	ft_moove(keycode, game);
	ft_collect(game);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == XK_Control_L)
		game->keycode_prev = 0;
	return (0);
}
