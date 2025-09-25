/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagsScC.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 03:46:55 by maechard          #+#    #+#             */
/*   Updated: 2017/11/27 03:46:57 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags(va_list aq, t_printf *tab)
{
	tab->ret = va_arg(aq, char*);
}

void	ft_flagc(va_list aq, t_printf *tab)
{
	tab->ret = ft_memalloc(2);
	tab->ret[0] = va_arg(aq, int);
	tab->ret[1] = '\0';
}

void	ft_flagC(va_list aq, t_printf *tab)
{
	int		s;

	s = 0;
	tab->Ch = va_arg(aq, wchar_t);
	tab->ret = ft_wchartostr(tab->Ch, &s);
}

void	ft_flagS(va_list aq, t_printf *tab)
{
	int		s;
	int		i;
	char	*st;

	i = 0;
	tab->St = va_arg(aq, wchar_t*);
	while (tab->St[i] != 0)
		i++;
	tab->ret = malloc(sizeof(wchar_t) * (i * 2) + 1);
	i = 0;
	while (tab->St[i] != 0)
	{
		s = 0;
		st = ft_wchartostr(tab->St[i], &s);
		tab->ret = ft_strjoin(tab->ret, st);
		i++;
	}
}