/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 19:01:30 by maechard          #+#    #+#             */
/*   Updated: 2017/03/10 13:16:04 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_display(char a, char b, char c, char d)
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

int		ft_deuxieme_boucle(int a, int b)
{
	char	c;
	char	d;

	c = 0;
	while (c <= 9)
	{
		d = 0;
		while (d <= 9)
		{
			if (b < d)
				ft_display(a, b, c, d);
			d++;
		}
		c++;
	}
	return (0);
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
