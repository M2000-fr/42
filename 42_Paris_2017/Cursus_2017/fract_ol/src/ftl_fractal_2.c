/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_fractal_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 09:27:47 by maechard          #+#    #+#             */
/*   Updated: 2018/08/06 09:27:50 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftl.h"

int		ftl_fractal_carpet(t_env *e, t_fractal ftl, t_point *point)
{
	int x;
	int y;

	(void)ftl;
	x = point->x;
	y = point->y;
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (ftl_get_color(0, *(e->p_color_ptr)));
		y /= 3;
		x /= 3;
	}
	return (ftl_get_color(100, *(e->p_color_ptr)));
}
