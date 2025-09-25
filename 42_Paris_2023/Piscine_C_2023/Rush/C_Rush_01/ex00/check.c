/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhadini <abhadini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 23:20:00 by abhadini          #+#    #+#             */
/*   Updated: 2023/08/13 23:35:47 by abhadini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"

int	check_colnline(int const tab[4][4], int const y, int const x,
		int const value)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i != x && tab[y][x] != 0 && tab[y][i] == value)
			return (0);
		else if (i != y && tab[i][x] != 0 && tab[i][x] == value)
			return (0);
		i++;
	}
	return (1);
}

int	is_filled_good(int const consign[4][4], int const tab[4][4])
{
	int	y;
	int	x;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (!check_colnline(tab, y, x, tab[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (check_all_views(consign, tab));
}
