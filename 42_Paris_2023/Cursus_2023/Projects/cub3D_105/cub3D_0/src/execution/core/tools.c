/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 08:43:41 by mechard           #+#    #+#             */
/*   Updated: 2025/04/04 08:43:41 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*             (Fonctions utilitaires : pixel et hook de sortie)              */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_render *r, int y, int color)
{
	int	idx;

	idx = (y * r->size_line) + (r->x * (r->bpp / 8));
	*(int *)(r->data + idx) = color;
}

int	exit_hook(t_cub *cub)
{
	free_all_cub(cub);
	if (cub->mlx && cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (cub->mlx)
	{
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
	}
	exit(0);
	return (0);
}
