/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 06:00:27 by tarchen           #+#    #+#             */
/*   Updated: 2017/11/21 00:12:19 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ligne_ver(t_all *all, int e[7], int color)
{
	int	i;

	i = 0;
	e[4] = e[0] / 2;
	while (++i <= e[0])
	{
		e[5] += e[2];
		e[4] += e[1];
		if (e[4] >= e[0])
		{
			e[4] -= e[0];
			e[6] += e[3];
		}
		mlx_pixel_put(all->mlx, all->win, e[5], e[6], color);
	}
}

void	ligne_hor(t_all *all, int e[7], int color)
{
	int	i;

	i = 0;
	e[4] = e[1] / 2;
	while (++i <= e[1])
	{
		e[6] += e[3];
		e[4] += e[0];
		if (e[4] >= e[1])
		{
			e[4] -= e[1];
			e[5] += e[2];
		}
		mlx_pixel_put(all->mlx, all->win, e[5], e[6], color);
	}
}

void	mlx_draw_line(t_all *all, int xi, int yi, int xf, int yf, int color)
{
	int	e[7];

 	e[5] = xi;
 	e[6] = yi;
 	e[0] = xf - xi;
 	e[1] = yf - yi;
 	e[2] = (e[0] > 0) ? 1 : -1;
 	e[3] = (e[1] > 0) ? 1 : -1;
 	e[0] = abs(e[0]);
 	e[1] = abs(e[1]);
 	mlx_pixel_put(all->mlx, all->win, e[5], e[6], color);
 	if (e[0] > e[1])
		ligne_ver(all, e, color);
	else
		ligne_hor(all, e, color);
}
