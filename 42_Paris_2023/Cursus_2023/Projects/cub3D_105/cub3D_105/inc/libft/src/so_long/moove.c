/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:02:35 by mechard           #+#    #+#             */
/*   Updated: 2024/07/08 13:18:00 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_moove_up(t_game *game)
{
	if (game->player_x % 64 == 0)
	{
		game->player_y -= 8;
		game->step++;
		ft_finish(game);
	}
	else if (game->map[(game->player_y - 8) / 64][(game->player_x / 64)
		+ 1] != '0')
	{
		game->player_y -= 8;
		game->step++;
		ft_finish(game);
	}
}

void	ft_moove_down(t_game *game)
{
	if (game->player_x % 64 == 0)
	{
		game->player_y += 8;
		game->step++;
		ft_finish(game);
	}
	else if (game->map[(game->player_y + 64) / 64][(game->player_x / 64)
		+ 1] != '0')
	{
		game->player_y += 8;
		game->step++;
		ft_finish(game);
	}
}

void	ft_moove_left(t_game *game)
{
	if (game->player_y % 64 == 0)
	{
		game->player_x -= 8;
		game->step++;
		ft_finish(game);
	}
	else if (game->map[(game->player_y / 64) + 1][(game->player_x - 8)
		/ 64] != '0')
	{
		game->player_x -= 8;
		game->step++;
		ft_finish(game);
	}
}

void	ft_moove_right(t_game *game)
{
	if (game->player_y % 64 == 0)
	{
		game->player_x += 8;
		game->step++;
		ft_finish(game);
	}
	else if (game->map[(game->player_y / 64) + 1][(game->player_x + 64)
		/ 64] != '0')
	{
		game->player_x += 8;
		game->step++;
		ft_finish(game);
	}
}

void	ft_moove(int keycode, t_game *game)
{
	if ((keycode == XK_Up || keycode == XK_w) && game->map[(game->player_y - 8)
			/ 64][game->player_x / 64] != '0')
		ft_moove_up(game);
	if ((keycode == XK_Down || keycode == XK_s) && game->map[(game->player_y
				+ 64) / 64][game->player_x / 64] != '0')
		ft_moove_down(game);
	if ((keycode == XK_Left || keycode == XK_a) && game->map[game->player_y
			/ 64][(game->player_x - 8) / 64] != '0')
		ft_moove_left(game);
	if ((keycode == XK_Right || keycode == XK_d) && game->map[game->player_y
			/ 64][(game->player_x + 64) / 64] != '0')
		ft_moove_right(game);
	ft_printf("\rLe nombre de pas est de %i", game->step);
}
