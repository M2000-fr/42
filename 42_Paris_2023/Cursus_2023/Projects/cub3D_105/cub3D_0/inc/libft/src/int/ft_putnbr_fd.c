/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:11:48 by mechard           #+#    #+#             */
/*   Updated: 2025/01/23 15:24:29 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		nb = -n;
		ft_putchar_fd('-', fd);
	}
	else
		nb = n;
	if (nb >= 10)
	{
		ft_putnbr_fd((nb / 10), fd);
		ft_putchar_fd(((nb % 10) + '0'), fd);
	}
	else
	{
		if (n > 0)
			ft_putchar_fd(('0' + n), fd);
		else
			ft_putchar_fd(('0' - n), fd);
	}
}

void	ft_putnbr_libft(int n)
{
	unsigned int	nb;

	if (n < 0)
	{
		nb = -n;
		ft_putchar_libft('-');
	}
	else
		nb = n;
	if (nb >= 10)
	{
		ft_putnbr_libft(nb / 10);
		ft_putchar_libft((nb % 10) + '0');
	}
	else
	{
		if (n > 0)
			ft_putchar_libft('0' + n);
		else
			ft_putchar_libft('0' - n);
	}
}
