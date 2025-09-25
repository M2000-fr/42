/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 08:40:36 by mechard           #+#    #+#             */
/*   Updated: 2025/04/04 08:40:36 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*               (Rendu des colonnes et des pixels de la scène)               */
/* ************************************************************************** */

#include "cub3d.h"

void	render_column(t_render *r, t_ray_result *res)
{
	render_column_ray(r, res);
	draw_column_pixels(r, res);
}

void	render_column_ray(t_render *r, t_ray_result *res)
{
	compute_ray_params(r, res);
	run_dda(r, res);
	compute_distances(r, res);
	select_texture(r, res);
	compute_texture(r, res);
}

void	draw_upper_and_wall_pixels(t_render *r, t_ray_result *res, int *py)
{
	int	color;
	int	d;
	int	texy;
	int	tmp_y;

	tmp_y = *py;
	while (tmp_y < res->drawstart)
	{
		color = (r->cub->color_ceiling[0] << 16)
			| (r->cub->color_ceiling[1] << 8)
			| r->cub->color_ceiling[2];
		(put_pixel(r, tmp_y, color), tmp_y++);
	}
	while (tmp_y <= res->drawend)
	{
		if (res->lineheight != 0)
		{
			d = tmp_y * 256 - WIN_HEIGHT * 128 + res->lineheight * 128;
			texy = ((d * res->current_tex->height) / res->lineheight) / 256;
			color = get_texture_pixel(res->current_tex, res->texx, texy);
			put_pixel(r, tmp_y, color);
		}
		tmp_y++;
	}
	*py = tmp_y;
}

void	draw_floor_pixels(t_render *r, int py)
{
	int	color;

	while (py < WIN_HEIGHT)
	{
		color = (r->cub->color_floor[0] << 16)
			| (r->cub->color_floor[1] << 8)
			| r->cub->color_floor[2];
		put_pixel(r, py, color);
		py++;
	}
}

void	draw_column_pixels(t_render *r, t_ray_result *res)
{
	int	y;

	y = 0;
	draw_upper_and_wall_pixels(r, res, &y);
	draw_floor_pixels(r, y);
}
