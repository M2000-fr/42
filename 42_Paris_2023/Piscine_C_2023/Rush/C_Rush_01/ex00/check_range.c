/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhadini <abhadini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 23:19:36 by abhadini          #+#    #+#             */
/*   Updated: 2023/08/13 23:34:14 by abhadini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"

int	check_top_range(int const consign[4][4], int const tab[4][4], int const x)
{
	int	y;
	int	count;
	int	max;
	int	view;

	y = 0;
	count = 0;
	max = 0;
	view = consign[TOP][x];
	while (y < 4)
	{
		if (tab[y][x] > max)
		{
			max = tab[y][x];
			count++;
		}
		y++;
	}
	return (count == view);
}

int	check_bottom_range(int const consign[4][4], int const tab[4][4],
		int const x)
{
	int	y;
	int	count;
	int	max;
	int	view;

	y = 3;
	count = 0;
	max = 0;
	view = consign[BOTTOM][x];
	while (y >= 0)
	{
		if (tab[y][x] > max)
		{
			max = tab[y][x];
			count++;
		}
		y--;
	}
	return (count == view);
}

int	check_left_range(int const consign[4][4], int const tab[4][4], int const x)
{
	int	y;
	int	count;
	int	max;
	int	view;

	y = 0;
	count = 0;
	max = 0;
	view = consign[LEFT][x];
	while (y < 4)
	{
		if (tab[x][y] > max)
		{
			max = tab[x][y];
			count++;
		}
		y++;
	}
	return (count == view);
}

int	check_right_range(int const consign[4][4], int const tab[4][4], int const x)
{
	int	y;
	int	count;
	int	max;
	int	view;

	y = 3;
	count = 0;
	max = 0;
	view = consign[RIGHT][x];
	while (y >= 0)
	{
		if (tab[x][y] > max)
		{
			max = tab[x][y];
			count++;
		}
		y--;
	}
	return (count == view);
}
