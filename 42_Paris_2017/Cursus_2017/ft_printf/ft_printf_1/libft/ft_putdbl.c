/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 12:44:53 by tarchen           #+#    #+#             */
/*   Updated: 2017/04/08 12:45:25 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void			ft_putdbl(double nbr, int i)
{
	int			int_part;

	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-');
	}
	int_part = nbr;
	nbr -= int_part;
	ft_putnbr(int_part);
	if (nbr != 0 && i)
		ft_putchar('.');
	while (nbr > 0 && i)
	{
		nbr *= 10;
		int_part = nbr;
		nbr -= int_part;
		ft_putnbr(int_part);
		i--;
	}
}
