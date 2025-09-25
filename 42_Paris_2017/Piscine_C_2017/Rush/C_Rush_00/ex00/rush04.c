/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 18:09:36 by maechard          #+#    #+#             */
/*   Updated: 2017/03/12 19:35:37 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_top_line(int a)
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

void	ft_bot_line(int a)
{
	int		b;

	b = 1;
	while (b <= a)
	{
		if (b == 1)
			ft_putchar('C');
		if (b < a && b > 1)
			ft_putchar('B');
		if (b == a && a > 1)
			ft_putchar('A');
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
		if (d == 1)
			ft_top_line(x);
		if (d >= 2 && d <= y - 1)
			ft_mid_line(x);
		if (d == y)
			ft_bot_line(x);
		d++;
	}
}
