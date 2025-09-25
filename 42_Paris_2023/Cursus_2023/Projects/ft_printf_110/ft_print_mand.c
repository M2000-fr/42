/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:59:05 by mechard           #+#    #+#             */
/*   Updated: 2023/12/05 17:30:32 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putnbr(int nb, int *len)
{
	if (nb < 0)
	{
		if (nb == INT_MIN)
		{
			write(1, "-2147483648", 11);
			*len += 11;
			return ;
		}
		nb = -nb;
		ft_putchar('-', len);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, len);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48, len);
}

void	ft_putnbr_base(unsigned long long nbr, char *base, int *len, char c)
{
	if (c == 'p')
	{
		if (nbr != 0)
			ft_putstr("0x", len);
		if (nbr == 0)
		{
			ft_putstr("(nil)", len);
			return ;
		}
		c++;
	}
	if (c != 'p')
	{
		if (nbr >= 16)
			ft_putnbr_base(nbr / 16, base, len, c);
		ft_putchar(base[nbr % 16], len);
	}
}

void	ft_putnbr_unsigned(unsigned int nb, int *len)
{
	if (nb >= 10)
	{
		ft_putnbr_unsigned(nb / 10, len);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48, len);
}

void	ft_putstr(char *str, int *len)
{
	if (!str)
		*len += write(1, "(null)", 6);
	else
		*len += write(1, str, ft_strlen(str));
}
