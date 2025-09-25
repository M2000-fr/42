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

#include "../include/ft_printf.h"

int		ft_recursive_power(long int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

void	Putpoint(t_printf *tab, char *res)
{
	long int	i;
	long int	j;

	i = 0;
	j = i;
	if (tab->e < 0)
		tab->v++;
	while (i <= tab->w)
	{
		if (i == tab->v && tab->v != -1)
		{
			tab->ret[i++] = '.';
			tab->v = -1;
		}
		tab->ret[i] = res[j];
		i++;
		j++;
	}
	tab->ret[--i] = '\0';

}

void	Floatonchar(long long int dbl, t_printf *tab)
{
	long int	nb;

	nb = 0;
	if (dbl < 0)
	{
		tab->ret[tab->i++] = '-';
		dbl = -dbl;
	}
	if (dbl < 10 && dbl > -1)
		tab->ret[tab->i++] = dbl + 48;
	if (tab->e < 1 && tab->e > -1 && tab->v == 0)
	{
		tab->v++;
		tab->ret[tab->i++] = '0';
	}
	else if (tab->e > 1 || tab->e < -1)
	{
		tab->e = tab->e / 10;
		tab->v++;
	}
	if (dbl >= 10)
	{
		nb = dbl;
		dbl = dbl / 10;
		Floatonchar(dbl, tab);
		dbl = nb % 10;
		Floatonchar(dbl, tab);
	}
}

void	ft_flagf(va_list aq, t_printf *tab)
{
	long long int	dbl;
	long int		nb;
	int				s;
	char			*res;

	tab->w = 0;
	s = 0;
	if (tab->prec == 0)
		tab->prec = 6;
	res = NULL;
	tab->e = va_arg(aq, double);
	nb = tab->e;
	dbl = fabs(tab->e);
	tab->v = 0;
	if (tab->e < 0)
	{
		tab->e = -tab->e;
		s = 1;
	}
	while (dbl - (tab->e * ft_recursive_power(10, tab->w)) != 0 && tab->w <= tab->prec)
		dbl = fabs(tab->e) * ft_recursive_power(10, tab->w++);
	if ((fabs(tab->e) * ft_recursive_power(10, tab->w + 1) -
		(tab->e * ft_recursive_power(10, tab->w + 1))) >= 5)
		dbl++;
	if (s == 1)
	{
		dbl = -dbl;
		tab->e = -tab->e;
	}
	if (tab->e < 0)
	{
		tab->w++;
		nb = nb * -1;
	}
	while (nb >= 10 || nb <= -10)
	{
		nb = nb / 10;
		tab->w++;
	}
	tab->w++;
	if(!(tab->ret = (char*)malloc(sizeof(char) * tab->w + 1)))
		return ;
	Floatonchar(dbl, tab);
	res = ft_strdup(tab->ret);
	Putpoint(tab, res);
	tab->ret[tab->w++] = '\0';
}