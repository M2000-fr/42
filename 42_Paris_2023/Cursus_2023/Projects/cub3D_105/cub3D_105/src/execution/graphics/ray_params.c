/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 08:34:07 by mechard           #+#    #+#             */
/*   Updated: 2025/04/04 08:34:07 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                   (Calcul des paramètres de raycasting)                    */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	compute_ray_params_part1(t_render *r, t_ray_result *res)
{
	res->camx = 2 * r->x / (double)WIN_WIDTH - 1;
	res->raydirx = r->cub->dirx + r->cub->planex * res->camx;
	res->raydiry = r->cub->diry + r->cub->planey * res->camx;
	res->mapx = (int)(r->cub->posx);
	res->mapy = (int)(r->cub->posy);
	if (res->raydirx == 0)
		res->deltadistx = 1e30;
	else
		res->deltadistx = fabs(1 / res->raydirx);
	if (res->raydiry == 0)
		res->deltadisty = 1e30;
	else
		res->deltadisty = fabs(1 / res->raydiry);
}

void	compute_ray_params_part2(t_render *r, t_ray_result *res)
{
	if (res->raydirx < 0)
	{
		res->stepx = -1;
		res->sidedistx = (r->cub->posx - res->mapx) * res->deltadistx;
	}
	else
	{
		res->stepx = 1;
		res->sidedistx = ((double)res->mapx + 1.0 - r->cub->posx)
			* res->deltadistx;
	}
	if (res->raydiry < 0)
	{
		res->stepy = -1;
		res->sidedisty = (r->cub->posy - res->mapy) * res->deltadisty;
	}
	else
	{
		res->stepy = 1;
		res->sidedisty = ((double)res->mapy + 1.0 - r->cub->posy)
			* res->deltadisty;
	}
	res->hit = 0;
}

void	compute_ray_params(t_render *r, t_ray_result *res)
{
	compute_ray_params_part1(r, res);
	compute_ray_params_part2(r, res);
}
