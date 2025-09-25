/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:33:38 by mechard           #+#    #+#             */
/*   Updated: 2023/08/02 11:33:55 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_display_2(char a, char b, char c, char d)
{
	ft_putchar(a + 48);
	ft_putchar(b + 48);
	ft_putchar(' ');
	ft_putchar(c + 48);
	ft_putchar(d + 48);
	if (!(a == 9 && b == 8 && c == 9 && d == 9))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_deuxieme_boucle(char a, char b)
{
	char	c;
	char	d;

	c = 0;
	while (c <= 9)
	{
		d = 0;
		while (d <= 9)
		{
			if (b < d && a <= c)
				ft_display_2(a, b, c, d);
			d++;
		}
	c++;
	}
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;

	a = 0;
	while (a <= 9)
	{
		b = 0;
		while (b <= 9)
		{
			ft_deuxieme_boucle(a, b);
			b++;
		}
		a++;
	}
}
