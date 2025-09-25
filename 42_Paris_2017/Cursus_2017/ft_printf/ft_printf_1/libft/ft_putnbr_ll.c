/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:46:46 by tarchen           #+#    #+#             */
/*   Updated: 2017/06/15 00:20:35 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <limits.h>

void	ft_putnbr_ll(long int n)
{
	if (n == LONG_MIN)
		ft_putstr("-9223372036854775808");
	if (n < 0 && n > LONG_MIN)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n < 10 && n > LONG_MIN)
		ft_putchar(n + 48);
	else if (n >= 10)
	{
		ft_putnbr_ll(n / 10);
		ft_putnbr_ll(n % 10);
	}
}
