/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo (1).c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhadini <abhadini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 23:18:59 by abhadini          #+#    #+#             */
/*   Updated: 2023/08/13 23:35:03 by abhadini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"

void	place(int const consign[4][4], int (*tab)[4][4], int pos)
{
	int	y;
	int	x;
	int	value;

	y = pos / 4;
	x = pos % 4;
	if (pos > 15)
		return ;
	if ((*tab)[y][x] != 0)
		place(consign, tab, pos + 1);
	else
	{
		value = 1;
		while (value <= 4)
		{
			(*tab)[y][x] = value;
			if (check_colnline(*tab, y, x, value))
				place(consign, tab, pos + 1);
			if (is_filled_good(consign, *tab))
				return ;
			value++;
		}
		(*tab)[y][x] = 0;
	}
}
