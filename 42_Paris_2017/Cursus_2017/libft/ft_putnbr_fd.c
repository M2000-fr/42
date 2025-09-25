/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 20:42:00 by maechard          #+#    #+#             */
/*   Updated: 2017/04/14 20:44:43 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
		ft_putstr_fd(("-2147483648"), fd);
	else
	{
		if (nb < 0 && nb != -2147483648)
		{
			ft_putchar_fd(('-'), fd);
			nb = -nb;
		}
		if (nb <= 9)
			ft_putchar_fd((nb + 48), fd);
		if (nb >= 10)
		{
			ft_putnbr_fd((nb / 10), fd);
			ft_putchar_fd((nb % 10 + 48), fd);
		}
	}
}
