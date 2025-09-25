/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 09:26:36 by maechard          #+#    #+#             */
/*   Updated: 2018/08/06 09:26:39 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftl.h"

static void		ftl_draw_fractal(t_env *e)
{
	ftl_cal_apply(e, e->ftl_ptr, e->ftl_ptr->func);
}

void			ftl_draw_windows(char *title, t_env *e)
{
	if (!(e->mlx = mlx_init()))
		ft_error_str_exit("error mlx init.\n");
	e->win = mlx_new_window(e->mlx, e->win_size_w, e->win_size_h, title);
}

void			ftl_draw_reload(t_env *e)
{
	e->img = mlx_new_image(e->mlx, e->win_size_w, e->win_size_h);
	e->pixel_img = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line), &(e->ed));
	ftl_draw_fractal(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
}

void			ftl_draw_pixel_img(t_point *point, t_env *e, int color)
{
	int i;

	i = ((int)point->x * 4) + ((int)point->y * e->s_line);
	e->pixel_img[i] = color;
	e->pixel_img[++i] = color >> 8;
	e->pixel_img[++i] = color >> 16;
}
