/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_draws.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 08:36:31 by mechard           #+#    #+#             */
/*   Updated: 2025/04/04 08:36:31 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                (Exécution du DDA et affichage de la scène)                 */
/* ************************************************************************** */

#include "cub3d.h"

void	run_dda(t_render *r, t_ray_result *res)
{
	while (res->hit == 0)
	{
		if (res->sidedistx < res->sidedisty)
		{
			res->sidedistx += res->deltadistx;
			res->mapx += res->stepx;
			res->side = 0;
		}
		else
		{
			res->sidedisty += res->deltadisty;
			res->mapy += res->stepy;
			res->side = 1;
		}
		if (r->cub->map[res->mapy][res->mapx] == '1')
			res->hit = 1;
	}
}

void	draw_scene(t_cub *cub)
{
	int				x;
	t_exec			ex;
	t_render		r;
	t_ray_result	res;

	x = 0;
	ex.img = mlx_new_image(cub->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (ex.img == 0)
		return ;
	ex.data = mlx_get_data_addr(ex.img, &ex.bpp, &ex.sl, &(int){0});
	while (x < WIN_WIDTH)
	{
		r.cub = cub;
		r.x = x;
		r.data = ex.data;
		r.bpp = ex.bpp;
		r.size_line = ex.sl;
		render_column(&r, &res);
		x++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, ex.img, 0, 0);
	mlx_destroy_image(cub->mlx, ex.img);
}
