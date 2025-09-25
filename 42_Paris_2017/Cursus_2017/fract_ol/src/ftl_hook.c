/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 09:27:47 by maechard          #+#    #+#             */
/*   Updated: 2018/08/06 09:27:50 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftl.h"

static	void	ftl_key_hook_scale(int keycode, t_env *e)
{
	double	zr;

	if (keycode == KEY_KP_PLUS)
	{
		e->ftl_ptr->zoom_ratio *= 1.1;
		zr = e->ftl_ptr->zoom_ratio;
		e->ftl_ptr->x1 += ((e->win_size_h / 2) / e->win_size_w / 2) / zr * 10;
		e->ftl_ptr->x2 += ((e->win_size_h / 2) / e->win_size_w / 2) / zr * 10;
		e->ftl_ptr->y1 += ((e->win_size_w / 2) / e->win_size_h / 2) / zr * 10;
		e->ftl_ptr->y2 += ((e->win_size_w / 2) / e->win_size_h / 2) / zr * 10;
	}
	else if (keycode == KEY_KP_MINUS)
	{
		e->ftl_ptr->zoom_ratio /= 1.1;
		zr = e->ftl_ptr->zoom_ratio;
		e->ftl_ptr->x1 += ((e->win_size_h / 2) / e->win_size_w / 2) / zr * 10;
		e->ftl_ptr->x2 += ((e->win_size_h / 2) / e->win_size_w / 2) / zr * 10;
		e->ftl_ptr->y1 += ((e->win_size_w / 2) / e->win_size_h / 2) / zr * 10;
		e->ftl_ptr->y2 += ((e->win_size_w / 2) / e->win_size_h / 2) / zr * 10;
	}
}

static	void	ftl_key_hook_translation(int keycode, t_env *e)
{
	if (keycode == KEY_UP || keycode == KEY_W)
	{
		e->ftl_ptr->y1 += 3 / (e->ftl_ptr->zoom_ratio * 20);
		e->ftl_ptr->y2 += 3 / (e->ftl_ptr->zoom_ratio * 20);
	}
	else if (keycode == KEY_DOWN || keycode == KEY_S)
	{
		e->ftl_ptr->y1 -= 3 / (e->ftl_ptr->zoom_ratio * 20);
		e->ftl_ptr->y2 -= 3 / (e->ftl_ptr->zoom_ratio * 20);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_A)
	{
		e->ftl_ptr->x1 += 3 / (e->ftl_ptr->zoom_ratio * 20);
		e->ftl_ptr->x2 += 3 / (e->ftl_ptr->zoom_ratio * 20);
	}
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
	{
		e->ftl_ptr->x1 -= 3 / (e->ftl_ptr->zoom_ratio * 20);
		e->ftl_ptr->x2 -= 3 / (e->ftl_ptr->zoom_ratio * 20);
	}
}

int				ftl_mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == KEY_MOUSE_UP || button == KEY_MOUSE_CLIC_L ||
		button == KEY_MOUSE_DOWN || button == KEY_MOUSE_CLIC_R)
	{
		e->ftl_ptr->x2 += (((double)x - e->win_size_h / 2) / e->win_size_w / 2)
						/ e->ftl_ptr->zoom_ratio * 5;
		e->ftl_ptr->y2 += (((double)y - e->win_size_w / 2) / e->win_size_h / 2)
						/ e->ftl_ptr->zoom_ratio * 5;
	}
	if (button == KEY_MOUSE_UP || button == KEY_MOUSE_CLIC_L)
	{
		e->ftl_ptr->zoom_ratio *= 1.1;
	}
	else if (button == KEY_MOUSE_DOWN || button == KEY_MOUSE_CLIC_R)
	{
		e->ftl_ptr->zoom_ratio /= 1.1;
	}
	ftl_draw_reload(e);
	return (0);
}

int				ftl_motion_hook(int x, int y, t_env *e)
{
	if (x >= 0 && y >= 0 && x <= e->win_size_w && y <= e->win_size_h
		&& e->stop_motion)
	{
		e->ftl_ptr->c.r = (double)x / (double)e->win_size_w * 4 - 2;
		e->ftl_ptr->c.i = (double)y / (double)e->win_size_h * 4 - 2;
		ftl_draw_reload(e);
	}
	return (0);
}

int				ftl_key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESC || keycode == 12)
	{
		mlx_destroy_window(e->mlx, e->win);
		free(e->ftl_arr);
		free(e->p_color_arr);
		free(e);
		exit(0);
	}
	else if (keycode == KEY_KP_0)
		e->stop_motion = !(e->stop_motion);
	else if (keycode == KEY_PAGE_UP)
		E += 5;
	else if (keycode == KEY_PAGE_DOWN)
	{
		if ((E - 5) <= 0 && (E - 1) >= 0)
			E -= 1;
		else
			E -= 5;
	}
	ftl_put_iter(keycode, e);
	ftl_key_hook_change_fractal(keycode, e);
	ftl_key_hook_scale(keycode, e);
	ftl_key_hook_translation(keycode, e);
	ftl_draw_reload(e);
	return (0);
}
