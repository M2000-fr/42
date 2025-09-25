/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagfF.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 03:46:55 by maechard          #+#    #+#             */
/*   Updated: 2017/11/27 03:46:57 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flagf(va_list aq, t_printf *tab)
{
	double	dbl;

	tab->len = 0;
	tab->prec = 6;
	tab->e = va_arg(aq, double);
	dbl = tab->e;
	tab->e *= ft_power(tab->prec, 10);
	// dbl = tab->e;
	printf("%f\n", dbl);
	while (dbl > 10 || dbl < -10)
	{
		dbl = dbl / 10;
		tab->len++;
	}
	if (tab->e < 0 && tab->e > (-1.797693e+308 - 1.000000e-308))
			tab->len++;
	tab->len += 3 + tab->prec;
	printf("e = %f\n", tab->e);
	printf("len = %ld\n", tab->len);
	tab->ret = ft_itoa_double(va_arg(aq, double), 10, 0, tab->len);
	printf("ret = %s\n", tab->ret);
}