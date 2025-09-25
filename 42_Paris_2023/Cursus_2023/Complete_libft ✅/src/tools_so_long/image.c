/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:19:05 by mechard           #+#    #+#             */
/*   Updated: 2024/07/08 13:17:47 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_init_sprites(t_game *game)
{
	int	taille;

	taille = 64;
	game->col = mlx_xpm_file_to_image(game->mlx_ptr, COL, &taille,
			&taille);
	if (!game->col)
		return (1);
	game->exi = mlx_xpm_file_to_image(game->mlx_ptr, EXI, &taille,
			&taille);
	if (!game->exi)
		return (1);
	game->roc = mlx_xpm_file_to_image(game->mlx_ptr, ROC, &taille,
			&taille);
	if (!game->roc)
		return (1);
	game->sol = mlx_xpm_file_to_image(game->mlx_ptr, SOL, &taille,
			&taille);
	if (!game->sol)
		return (1);
	game->pla = mlx_xpm_file_to_image(game->mlx_ptr, PLA, &taille,
			&taille);
	if (!game->pla)
		return (1);
	return (0);
}

void	draw_sprite(t_game *game, t_img *img, int x, int y)
{
	int				i;
	int				j;
	unsigned int	color;

	if (!img)
		return ;
	i = 0;
	while (i < img->width)
	{
		j = -1;
		while (++j < img->height)
		{
			if (j + x < 0 || j + x >= game->len * 64 || i + y < 0 || i
				+ y >= game->width * 64)
				continue ;
			color = ((int *)img->data)[i * img->width + j];
			if (color == 0xFF000000)
				continue ;
			((int *)game->canva->data)[((y + i) * (game->canva->width) + (x
						+ j))] = color;
		}
		i++;
	}
}

int	ft_set_img(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			if (game->map[i][j] == '1' || game->map[i][j] == 'P')
				draw_sprite(game, game->sol, j * 64, i * 64);
			else if (game->map[i][j] == '0')
				draw_sprite(game, game->roc, j * 64, i * 64);
			else if (game->map[i][j] == 'C')
				draw_sprite(game, game->col, j * 64, i * 64);
			else if (game->map[i][j] == 'E')
				draw_sprite(game, game->exi, j * 64, i * 64);
			j++;
		}
		i++;
	}
	draw_sprite(game, game->pla, game->player_x, game->player_y);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->canva, 0, 0);
	return (0);
}
