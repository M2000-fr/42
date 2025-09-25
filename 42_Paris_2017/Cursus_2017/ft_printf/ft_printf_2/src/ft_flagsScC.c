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

#include "../include/ft_printf.h"

void	ft_flags(va_list aq, t_printf *tab)
{
	if (tab->ret != NULL)
		free(tab->ret);
	tab->ret = va_arg(aq, char*);
}

void	ft_flagc(va_list aq, t_printf *tab)
{
	tab->c = 0;
	tab->c = va_arg(aq, int);
	if (tab->ret != NULL)
		free(tab->ret);
	tab->ret = (char*)malloc(sizeof(char) * 1);
	tab->ret[0] = tab->c;
}