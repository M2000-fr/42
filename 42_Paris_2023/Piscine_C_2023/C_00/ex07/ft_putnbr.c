/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:43:36 by mechard           #+#    #+#             */
/*   Updated: 2023/08/02 15:43:54 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		add;

	add = 0;
	while (str[add] != '\0')
	{
		ft_putchar(str[add]);
		add++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb -= nb;
		}
		if (nb <= 9)
			ft_putchar(nb + 48);
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
			ft_putchar(nb % 10 +48);
		}
	}
}
