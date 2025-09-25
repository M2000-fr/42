/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 03:46:55 by maechard          #+#    #+#             */
/*   Updated: 2017/11/27 03:46:57 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_flagp(va_list aq, t_printf *tab)
{
  unsigned long   adr;
  void            *ptr;
  char            *base;
  int             i;
 
  i = 11;
  ptr = va_arg(aq, void*);
  adr = (unsigned long)ptr;
  base = "0123456789abcdef";
  tab->ret = (char*)malloc(sizeof(char) * 13);
  while ((adr / 16) > 0 || i >= 8)
    {
      tab->ret[i] = base[(adr % 16)];
      adr /= 16;
      i--;
    }
  tab->ret[i] = base[(adr % 16)];
  base = "0x";
  tab->ret = ft_strjoin(base, tab->ret);
}