/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:30:03 by maechard          #+#    #+#             */
/*   Updated: 2017/03/12 19:34:34 by maechard         ###   ########.fr       */
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
			ft_putchar('/');
		if (b < a && b > 1)
			ft_putchar('*');
		if (b == a && a > 1)
			ft_putchar('\\');
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
			ft_putchar('\\');
		if (b < a && b > 1)
			ft_putchar('*');
		if (b == a && a > 1)
			ft_putchar('/');
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
			ft_putchar('*');
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
		if (d == y && y > 1)
			ft_bot_line(x);
		d++;
	}
}
