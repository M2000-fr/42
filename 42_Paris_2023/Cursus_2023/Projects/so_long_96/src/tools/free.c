/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:48:59 by mechard           #+#    #+#             */
/*   Updated: 2024/06/25 12:32:20 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_dfree(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str && str[i])
		free(str[i++]);
	free(str);
}

int	mlx_destroy_sprites(t_game *game)
{
	if (!game)
		return (0);
	if (game->col)
		mlx_destroy_image(game->mlx_ptr, game->col);
	if (game->exi)
		mlx_destroy_image(game->mlx_ptr, game->exi);
	if (game->roc)
		mlx_destroy_image(game->mlx_ptr, game->roc);
	if (game->sol)
		mlx_destroy_image(game->mlx_ptr, game->sol);
	if (game->pla)
		mlx_destroy_image(game->mlx_ptr, game->pla);
	if (game->canva)
		mlx_destroy_image(game->mlx_ptr, game->canva);
	return (0);
}

void	free_game(t_game *game)
{
	mlx_destroy_sprites(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	ft_dfree(game->map);
	free(game);
}
