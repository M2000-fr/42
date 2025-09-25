/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 12:23:03 by maechard          #+#    #+#             */
/*   Updated: 2017/03/19 21:41:14 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int		ft_tableau_sudoku(char tab[9] [9], char **argv)
{
	int		a;
	int		b;

	b = 0;
	while (b < 9)
	{
		a = 0;
		while (a < 9)
		{
			if (argv[b] [a] >= 48 && argv[b] [a] <= 57)
				tab[b] [a] = argv[b] [a];
			else if (argv[b] [a] == '.')
				tab[b] [a] = '0';
			else
				return (0);
			a++;
		}
		if (argv[b] [a])
			return (0);
		b++;
	}
	return (1);
}

void	ft_display_sudoku(char tab[9] [9])
{
	int		a;
	int		b;

	a = 0;
	while (a < 9)
	{
		b = 0;
		while (b < 9)
		{
			ft_putchar(tab[a] [b]);
				if (b != 8)
					ft_putchar(' ');
			b++;
		}
		ft_putchar('\n');
		a++;
	}
}

void	ft_save_ori(char ori[9] [9], char tab[9] [9])
{
	int		a;
	int		b;

	b = 0;
	while (b < 9)
	{
		a = 0;
		while (a < 9)
		{
			ori[b] [a] = tab[b] [a];
			a++;
		}
		b++;
	}
}
