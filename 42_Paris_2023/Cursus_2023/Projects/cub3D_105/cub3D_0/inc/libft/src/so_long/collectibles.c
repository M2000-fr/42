/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:53:56 by mechard           #+#    #+#             */
/*   Updated: 2024/07/08 13:17:32 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_col(t_game *game, int y, int x)
{
	game->map[y / 64][x / 64] = '1';
	game->collectibles++;
}

void	ft_end(t_game *game)
{
	int		taille;

	taille = 64;
	if (game->collectibles == game->nb_collectibles)
	{
		mlx_destroy_image(game->mlx_ptr, game->exi);
		game->exi = mlx_xpm_file_to_image(game->mlx_ptr, FIN,
				&taille, &taille);
		if (!game->exi)
		{
			ft_printf(ERROR_COL);
			return ;
		}
		game->exit = 1;
	}
}

void	ft_collect(t_game *game)
{
	if (game->map[(game->player_y + 48) / 64][game->player_x / 64] == 'C')
		ft_col(game, game->player_y + 48, game->player_x);
	if (game->player_y % 64 != 0 && game->map[(game->player_y + 48)
			/ 64][game->player_x / 64] == 'C')
		ft_col(game, game->player_y + 48, game->player_x);
	if (game->player_x % 64 != 0 && game->map[(game->player_y)
			/ 64][(game->player_x + 48) / 64] == 'C')
		ft_col(game, game->player_y, game->player_x + 48);
	if (game->player_y % 64 != 0 && game->player_x % 64 != 0
		&& game->map[(game->player_y + 48) / 64][(game->player_x + 48)
		/ 64] == 'C')
		ft_col(game, game->player_y + 48, game->player_x + 48);
	ft_end(game);
}
