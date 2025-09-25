/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 08:33:16 by mechard           #+#    #+#             */
/*   Updated: 2025/04/04 08:33:16 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*          (Calcul des distances et textures pour raycasting)                */
/* ************************************************************************** */

#include "cub3d.h"

void	compute_distances(t_render *r, t_ray_result *res)
{
	if (res->side == 0)
		res->perpwalldist = ((double)res->mapx - r->cub->posx
				+ (1 - res->stepx) / 2.0) / res->raydirx;
	else
		res->perpwalldist = ((double)res->mapy - r->cub->posy
				+ (1 - res->stepy) / 2.0) / res->raydiry;
	res->lineheight = (int)(WIN_HEIGHT / res->perpwalldist);
	res->drawstart = -res->lineheight / 2 + WIN_HEIGHT / 2;
	if (res->drawstart < 0)
		res->drawstart = 0;
	res->drawend = res->lineheight / 2 + WIN_HEIGHT / 2;
	if (res->drawend >= WIN_HEIGHT)
		res->drawend = WIN_HEIGHT - 1;
}

void	select_texture(t_render *r, t_ray_result *res)
{
	if (res->side == 0)
	{
		if (res->raydirx < 0)
			res->current_tex = &r->cub->img_tex_ea;
		else
			res->current_tex = &r->cub->img_tex_we;
	}
	else
	{
		if (res->raydiry < 0)
			res->current_tex = &r->cub->img_tex_no;
		else
			res->current_tex = &r->cub->img_tex_so;
	}
}

void	compute_texture(t_render *r, t_ray_result *res)
{
	if (res->side == 0)
		res->wallx = r->cub->posy + res->perpwalldist * res->raydiry;
	else
		res->wallx = r->cub->posx + res->perpwalldist * res->raydirx;
	res->wallx = res->wallx - floor(res->wallx);
	res->texx = (int)(res->wallx * res->current_tex->width);
	if ((res->side == 0 && res->raydirx < 0)
		|| (res->side == 1 && res->raydiry > 0))
		res->texx = res->current_tex->width - res->texx - 1;
}
