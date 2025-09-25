/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagoxOX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 03:46:55 by maechard          #+#    #+#             */
/*   Updated: 2017/11/27 03:46:57 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		Intonoct(t_printf *tab)
{
	int		nb;

	nb = tab->nbr;
	if (tab->nbr < 8)
		tab->ret[tab->i++] = tab->nbr + 48;
	if (tab->nbr >= 8)
	{
		tab->nbr = nb / 8;
		Intonoct(tab);
		tab->nbr = nb % 8;
		Intonoct(tab);
	}
}

void		ft_flagoO(va_list aq, t_printf *tab)
{
	unsigned int		nb;

	tab->nbr = va_arg(aq, unsigned int);
	tab->len = 0;
	nb = tab->nbr;
	while (nb > 8)
	{
		nb = nb / 8;
		tab->len++;
	}
	if (nb <= 8)
		tab->len++;
	tab->ret = (char*)malloc(sizeof(char) * tab->len);
	nb = 0;
	Intonoct(tab);
}

void		Intonhex(t_printf *tab)
{
	int		nb;
	char	*hex;

	nb = tab->nbr;
	hex = "0123456789abcdef";
	if (tab->f == 'X')
		hex = "0123456789ABCDEF";
	nb = tab->nbr;
	if (tab->nbr < 16)
		tab->ret[tab->i++] = hex[nb];
	if (tab->nbr >= 16)
	{
		tab->nbr = tab->nbr / 16;
		Intonhex(tab);
		tab->nbr = nb % 16;
		Intonhex(tab);
	}
}

void	ft_flagxX(va_list aq, t_printf *tab)
{
	unsigned int		nb;

	tab->nbr = va_arg(aq, unsigned int);
	tab->len = 0;
	nb = tab->nbr;
	while (nb > 16)
	{
		nb = nb / 16;
		tab->len++;
	}
	if (nb <= 16)
		tab->len++;
	tab->ret = (char*)malloc(sizeof(char) * tab->len);
	nb = 0;
	Intonhex(tab);
}