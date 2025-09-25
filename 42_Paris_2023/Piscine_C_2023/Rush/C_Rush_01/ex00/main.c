/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhadini <abhadini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 23:19:41 by abhadini          #+#    #+#             */
/*   Updated: 2023/08/13 23:32:57 by abhadini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"

void	ft_putchar(char const c)
{
	write(1, &c, 1);
}

int	check_consign(char const *consign)
{
	int	i;
	int	nb_count;
	int	size;

	i = 0;
	nb_count = 0;
	size = 0;
	while (consign[size] != '\0')
		size++;
	if (size != 31)
		return (0);
	while (consign[i] != '\0')
	{
		if (!(consign[i] >= '1' && consign[i] <= '4') && consign[i] != ' ')
			return (0);
		if (consign[i] >= '1' && consign[i] <= '4')
			nb_count++;
		i++;
	}
	return (nb_count == 16);
}

void	set_consign(char const *consign, int (*tab)[4][4])
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = 0;
	x = 0;
	while (consign[i] != '\0')
	{
		if (i != 0 && i % 8 == 0)
		{
			y++;
			x = 0;
		}
		if (consign[i] >= '1' && consign[i] <= '4')
			(*tab)[y][x++] = consign[i] - '0';
		i++;
	}
}

void	print_tab(int const tab[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(tab[i][j] + '0');
			if (j < 3)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	main(int ac, char const **av)
{
	int	res;
	int	consign[4][4];
	int	tab[4][4];

	if (ac == 2)
	{
		init_tab(&tab);
		res = check_consign(av[1]);
		if (res == 0)
			write(1, "Error\n", 6);
		else
		{
			set_consign(av[1], &consign);
			place1234_front_of_4(consign, &tab);
			place4_front_of_1(consign, &tab);
			place(consign, &tab, 0);
			if (is_filled_good(consign, tab))
				print_tab(tab);
			else
				write(1, "Error\n", 6);
		}
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
