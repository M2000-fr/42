/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagxX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           *///4294967295
/*   Created: 2017/11/27 03:46:55 by maechard          #+#    #+#             */
/*   Updated: 2017/11/27 03:46:57 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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