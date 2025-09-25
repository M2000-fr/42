/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 12:04:00 by maechard          #+#    #+#             */
/*   Updated: 2017/03/19 21:41:11 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_tableau_sudoku(char tab[9] [9], char **argv);
void	ft_display_sudoku(char tab[9] [9]);
void	ft_putchar(char c);
void	ft_save_ori(char ori[9][9], char tab[9][9]);

int		ft_is_square(char tab[9] [9], int b, int c, int d)
{
	int		bmax;
	int		cmax;
	int		bmin;
	int		cmin;
	int		i;

	bmin = (b / 3) * 3;
	bmax = bmin + 3;
	cmin = (c / 3) * 3;
	cmax = cmin + 3;
	while (bmin < bmax)
	{
		i = cmin;
		while (i < cmax)
		{
			if (tab[bmin] [i] == d)
				return (0);
			i++;
		}
		bmin++;
	}
	return (1);
}

int		ft_address(char tab[9] [9], int b, int c, int d)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		if (i != b && tab[b] [i] == d)
			return (0);
		i++;
	}
	i = 0;
	while (i < 9)
	{
		if (i != c && tab[i] [c] == d)
			return (0);
		i++;
	}
	i = ft_is_square(tab, b, c, d);
	return (i);
}

int		ft_sudoku(char tab[9] [9], int value, char ori[9] [9])
{
	int		a;
	int		b;
	int		c;
	int		d;

	a = 0;
	b = value / 9;
	c = value % 9;
	if (b == 9 || c == 9)
	{
		printf("%s", tab[8]);
		ft_save_ori(ori, tab);
		return (1);
	}
	if (tab[b] [c] != '0')
	{
		a = ft_sudoku(tab, value + 1, ori);
		return (a);
	}
	d = '1';
	while (d <= '9')
	{
		if (ft_address(tab, b, c, d))
		{
			tab[b] [c] = d;
			a = a + ft_sudoku(tab, value + 1, ori);
			if (a > 1)
				return (a);
			tab[b] [c] = 0;
		}
		d++;
	}
	return (a);
}

int		main(int argc, char **argv)
{
	char	tab[9] [9];
	char	ori[9] [9];
	int		a;

	if (argc == 10)
		if (ft_tableau_sudoku(tab, &argv[1]))
		{
			a = ft_sudoku(tab, 0, ori);
			printf("%d", a);
			if (a == 1)
			{
				ft_display_sudoku(ori);
				return (0);
			}
		}
	write(1, "Error\n", 6);
	return (0);
}
