/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdbl_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 12:44:53 by tarchen           #+#    #+#             */
/*   Updated: 2017/04/20 04:13:53 by Theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void			ft_putdbl_fd(double nbr, int i, int fd)
{
	int			int_part;

	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar_fd('-', fd);
	}
	int_part = nbr;
	nbr -= int_part;
	ft_putnbr_fd(int_part, fd);
	if (nbr != 0 && i)
		ft_putchar_fd('.', fd);
	while (nbr > 0 && i)
	{
		nbr *= 10;
		int_part = nbr;
		nbr -= int_part;
		ft_putnbr_fd(int_part, fd);
		i--;
	}
}
