/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 11:15:02 by maechard          #+#    #+#             */
/*   Updated: 2017/03/17 12:14:58 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0 && nb != -2147483648)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb <= 9)
	{
		ft_putchar(nb + 48);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
}

void	ft_takes_place(int hour)
{
	write(1, "THE FOLLOWING TAKES PLACE BETWEEN ", 34);
	if (hour < 9 || hour == 24)
	{
		if (hour == 24)
			hour = 12;
		else
			write(1, "0", 1);
		ft_putnbr(hour);
		write(1, ".00 A.M. AND ", 13);
		if (hour == 12)
			hour = 0;
		write(1, "0", 1);
		ft_putnbr(hour + 1);
		write(1, ".00 A.M. \n", 10);
	}
	if (hour < 11 && hour > 9)
	{
		ft_putnbr(hour);
		write(1, ".00 A.M. AND ", 13);
		ft_putnbr(hour + 1);
		write(1, ".00 A.M. \n", 10);
	}
	if (hour == 11)
	{
		ft_putnbr(hour);
		write(1, ".00 A.M. AND ", 13);
		ft_putnbr(hour + 1);
		write(1, ".00 P.M. \n", 10);
	}
	if (hour > 11)
	{
		hour -= 12;
		if (hour < 9)
			write(1, "0", 1);
		ft_putnbr(hour);
		write(1, ".00 P.M. AND ", 13);
		write(1, "0", 1);
		ft_putnbr(hour + 1);
		write(1, ".00 P.M. \n", 10);
	}
}

int		main(void)
{
	int		hour;
	
	hour = 24;
	ft_takes_place(hour);
	return (0);
}
