/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagdDi.c                                       :+:      :+:    :+:   */
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
	int				nb;

	nb = 0;
	if (tab->nb < 0 && tab->nb > -2147483648)
	{
		tab->ret[tab->i++] = '-';
		tab->nb *= -1;
	}
	if (tab->nb < 10 && tab->nb > -1)
		tab->ret[tab->i++] = tab->nb + 48;
	else if (tab->nb >= 10)
	{
		nb = tab->nb;
		tab->nb = tab->nb / 10;
		Intonchar(tab);
		tab->nb = nb % 10;
		Intonchar(tab);
	}
}

void		ft_flagdDi(va_list aq, t_printf *tab)
{
	int		nb;

	tab->nb = va_arg(aq, int);
	tab->len = 0;
	nb = tab->nb;
	if (tab->nb == -2147483648)
		tab->ret = "-2147483648";
	else
	{
		if (tab->nb < 0 && tab->nb > -2147483648)
		{
			tab->len++;
			nb = nb * -1;
		}
		while (nb >= 10 || nb <= -10)
		{
			nb = nb / 10;
			tab->len++;
		}
		tab->ret = (char*)malloc(sizeof(char) * tab->len);
		nb = 0;
		Intonchar(tab);
	}
}