/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagdDip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 03:46:55 by maechard          #+#    #+#             */
/*   Updated: 2017/11/27 03:46:57 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	Intonchar(t_printf *tab)
{
	int		nb;

	nb = tab->c;
	if (nb < 0 && nb > -2147483648)
	{
		tab->ret[tab->i++] = '-';
		nb *= -1;
	}
	if (nb < 10)
		tab->ret[tab->i++] = nb + 48;
	else if (nb >= 10)
	{
		tab->c = nb / 10;
		Intonchar(tab);
		tab->c = nb % 10;
		Intonchar(tab);
	}
	tab->ret[tab->i] = '\0';
}

void		ft_flagdDi(va_list aq, t_printf *tab)
{
	tab->c = va_arg(aq, int);
	tab->i = tab->c;
	tab->len = 0;
	if (tab->c > -2147483648 && tab->c <= 2147483647)
	{
		while (tab->i >= 10 || tab->i <= -10)
		{
			if (tab->i < 0 && tab->i > -2147483648 && tab->len++ == 1)
				tab->i = tab->i * -1;
			tab->i = tab->i / 10;
			tab->len++;
		}
		tab->ret = ft_memalloc(tab->len);
		tab->i = 0;
		Intonchar(tab);
	}
	else if (tab->c == -2147483648)
		tab->ret = "-2147483648";
}