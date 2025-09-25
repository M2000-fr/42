/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:58:57 by mechard           #+#    #+#             */
/*   Updated: 2023/08/05 20:59:00 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_top_line(int x)
{
	int	b;

	b = 1;
	while (b <= x)
	{
		if (b == 1)
			ft_putchar('/');
		if (b < x && b > 1)
			ft_putchar('*');
		if (b == x && x != 1)
			ft_putchar('\\');
		b++;
	}
	ft_putchar('\n');
}

void	ft_mid_line(int x, int y)
{
	int	i;
	int	j;

	i = 1;
	x--;
	y--;
	while (i > 0 && i < y)
	{
		j = 0;
		while (j <= x)
		{
			if (j == 0 || j == x)
				ft_putchar('*');
			if (j > 0 && j < x)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	ft_bot_line(int x)
{
	int	b;

	b = 1;
	while (b <= x)
	{
		if (b == 1)
			ft_putchar('\\');
		if (b < x && b > 1)
			ft_putchar('*');
		if (b == x && x != 1)
			ft_putchar('/');
		b++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (x > 0 && y > 0)
	{
		ft_top_line(x);
		ft_mid_line(x, y);
		if (y > 1)
			ft_bot_line(x);
	}
}
