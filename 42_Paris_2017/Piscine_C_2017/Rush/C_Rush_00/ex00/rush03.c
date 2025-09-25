/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 10:51:58 by maechard          #+#    #+#             */
/*   Updated: 2017/03/13 12:08:13 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_top_bot_line(int a)
{
	int		b;

	b = 1;
	while (b <= a)
	{
		if (b == 1)
			ft_putchar('A');
		if (b < a && b > 1)
			ft_putchar('B');
		if (b == a && a > 1)
			ft_putchar('C');
		b++;
	}
	ft_putchar('\n');
}

void	ft_mid_line(int a)
{
	int		b;

	b = 1;
	while (b <= a)
	{
		if (b == 1 || b == a)
			ft_putchar('B');
		else
			ft_putchar(' ');
		b++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int		d;

	d = 1;
	if (x <= 0 || y <= 0)
		return ;
	while (d <= y)
	{
		while (d == 1 || d == y)
		{
			ft_top_bot_line(x);
			d++;
		}
		while (d >= 2 && d <= y - 1)
		{
			ft_mid_line(x);
			d++;
		}
	}
}
