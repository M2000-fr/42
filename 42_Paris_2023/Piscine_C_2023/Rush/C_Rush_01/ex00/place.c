/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhadini <abhadini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 22:23:31 by ahadini           #+#    #+#             */
/*   Updated: 2023/08/13 23:31:12 by abhadini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"

void	placetopbottom(int (*tab)[4][4], int x, int y, int value)
{
	int	index;

	index = 1;
	while (index >= 1 && index <= 4 && x < 4)
	{
		if (value == 0)
			(*tab)[x++][y] = index++;
		else
			(*tab)[x++][y] = value - index++;
	}
}

void	placeleftright(int (*tab)[4][4], int x, int y, int value)
{
	int	index;

	index = 1;
	while (index >= 1 && index <= 4 && y < 4)
	{
		if (value == 0)
			(*tab)[x][y++] = index++;
		else
			(*tab)[x][y++] = value - index++;
	}
}

void	place1234_front_of_4(int const consign[4][4], int (*tab)[4][4])
{
	int	y;
	int	x;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (consign[y][x] == 4)
			{
				if (y == TOP)
					placetopbottom(tab, 0, x, 0);
				else if (y == BOTTOM)
					placetopbottom(tab, 0, x, 5);
				else if (y == LEFT)
					placeleftright(tab, (x - y) + 2, 0, 0);
				else if (y == RIGHT)
					placeleftright(tab, (x - y) + 3, 0, 5);
			}
			x++;
		}
		y++;
	}
}

void	place4_front_of_1(int const consign[4][4], int (*tab)[4][4])
{
	int	y;
	int	x;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (consign[y][x] == 1)
			{
				if (y == TOP)
					(*tab)[0][x] = 4;
				else if (y == BOTTOM)
					(*tab)[3][x] = 4;
				else if (y == LEFT)
					(*tab)[(x - y) + 2][0] = 4;
				else if (y == RIGHT)
					(*tab)[(x - y) + 3][3] = 4;
			}
			x++;
		}
		y++;
	}
}
