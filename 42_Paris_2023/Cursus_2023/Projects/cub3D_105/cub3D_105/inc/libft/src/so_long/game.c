/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:29:38 by mechard           #+#    #+#             */
/*   Updated: 2024/07/08 13:17:27 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	close_window(t_game *game)
{
	free_game(game);
	exit(0);
	return (0);
}

void	*open_windows(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return (free(game), NULL);
	if (ft_init_sprites(game))
		return (free_game(game), NULL);
	game->win_ptr = mlx_new_window(game->mlx_ptr, (game->len * 64), (game->width
				* 64), "so_long");
	game->canva = mlx_new_image(game->mlx_ptr, (game->len * 64), (game->width
				* 64));
	if (game->win_ptr == NULL)
		return (free_game(game), NULL);
	mlx_loop_hook(game->mlx_ptr, &ft_set_img, game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, (int (*)())key_press,
		(void *)game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, (int (*)())key_release,
		(void *)game);
	mlx_hook(game->win_ptr, DestroyNotify, NoEventMask, (int (*)())close_window,
		(void *)game);
	mlx_loop(game->mlx_ptr);
	return (NULL);
}
