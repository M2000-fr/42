/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhadini <abhadini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 23:19:54 by abhadini          #+#    #+#             */
/*   Updated: 2023/08/13 23:35:06 by abhadini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"

int	check_top(int const consign[4][4], int const tab[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_top_range(consign, tab, i))
			return (0);
		i++;
	}
	return (1);
}

int	check_bottom(int const consign[4][4], int const tab[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_bottom_range(consign, tab, i))
			return (0);
		i++;
	}
	return (1);
}

int	check_left(int const consign[4][4], int const tab[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_left_range(consign, tab, i))
			return (0);
		i++;
	}
	return (1);
}

int	check_right(int const consign[4][4], int const tab[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_right_range(consign, tab, i))
			return (0);
		i++;
	}
	return (1);
}

int	check_all_views(int const consign[4][4], int const tab[4][4])
{
	return (check_top(consign, tab) && check_bottom(consign, tab)
		&& check_left(consign, tab) && check_right(consign, tab));
}
