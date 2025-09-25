/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:10:23 by mechard           #+#    #+#             */
/*   Updated: 2023/12/05 16:55:23 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_sharp(char c, va_list args, int *len)
{
	unsigned int	nb;

	nb = (unsigned int)va_arg(args, unsigned int);
	if (nb == 0)
		ft_putchar('0', len);
	if (c == 'x' && nb > 0)
	{
		ft_putstr("0x", len);
		ft_putnbr_base(nb, "0123456789abcdef", len, 'x');
	}
	else if (c == 'X' && nb > 0)
	{
		ft_putstr("0X", len);
		ft_putnbr_base(nb, "0123456789ABCDEF", len, 'X');
	}
}

void	ft_flag_plus(char *str, va_list args, int *len)
{
	int	nb;
	int	i;

	i = 0;
	nb = (int)va_arg(args, int);
	if ((str[i] == 'd' || str[i] == 'i') && str[i - 1] == '+' && nb >= 0)
		ft_putchar('+', len);
	ft_putnbr(nb, len);
	va_end(args);
}

int	ft_flag_space(char *str, va_list args, int *len)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == 'd' || str[i] == 'i')
	{
		nb = (int)va_arg(args, int);
		if (nb >= 0)
			ft_putchar(' ', len);
		ft_putnbr(nb, len);
	}
	else
		i += ft_check_mand(str + i, args, len);
	va_end(args);
	return (i);
}

int	ft_check_mand(char *str, va_list args, int *len)
{
	int	i;

	i = 0;
	if (str[i] == 'c')
		ft_putchar((char)va_arg(args, int), len);
	else if (str[i] == 's')
		ft_putstr((char *)va_arg(args, char *), len);
	else if (str[i] == 'i' || str[i] == 'd')
		ft_putnbr((int)va_arg(args, int), len);
	else if (str[i] == '%')
		ft_putchar('%', len);
	else if (str[i] == 'u')
		ft_putnbr_unsigned((unsigned int)va_arg(args, unsigned int), len);
	else if (str[i] == 'x')
		ft_putnbr_base((unsigned int)va_arg(args, unsigned int),
			"0123456789abcdef", len, 'x');
	else if (str[i] == 'X')
		ft_putnbr_base((unsigned int)va_arg(args, unsigned int),
			"0123456789ABCDEF", len, 'X');
	else if (str[i] == 'p')
		ft_putnbr_base((unsigned long long)va_arg(args, unsigned long long),
			"0123456789abcdef", len, 'p');
	va_end(args);
	return (i);
}

int	ft_check_bonu(char *str, va_list args, int *len)
{
	int	i;
	int	nb;

	i = 1;
	nb = 0;
	if (str[0] == '#')
		ft_flag_sharp(str[i], args, len);
	else if (str[0] == '+')
		ft_flag_plus(str + i, args, len);
	else if (str[0] == ' ')
		ft_flag_space(str, args, len);
	return (i);
}
