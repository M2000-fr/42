/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flageE.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 03:46:55 by maechard          #+#    #+#             */
/*   Updated: 2017/11/27 03:46:57 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*Dblonchar(t_printf *tab, char *str)
{
	int		e;
	int		i;
	char	*pwr;

	e = 0;
	i = 0;
	pwr = malloc(sizeof(char) * 11);
	if (tab->c < 0 && tab->c > -10000000)
	{
		str[tab->i++] = '-';
		tab->c *= -1;
	}
	if (tab->c < 10 && tab->c >= 0)
		str[tab->i++] = tab->c + 48;
	else if (tab->c >= 10)
	{
		e = tab->c;
		tab->c = tab->c / 10;
		Dblonchar(tab, str);
		tab->c = e % 10;
		Dblonchar(tab, str);
	}
	str[tab->i] = '\0';
	e = 0;
	while (str[i] != '\0')
	{
		if((e == 1 && str[0] != '-') || (e == 2 && str[0] == '-'))
			pwr[e++] = '.';
		pwr[e++] = str[i++];
	}
	pwr[e] = tab->f;
	e += 1;
	if (tab->nb >= 0 && tab->nb < 309)
		pwr[e++] = '+';
	else if (tab->nb < 0 && tab->nb > -309)
		pwr[e++] = '-';
	if(tab->nb < 10 && tab->nb > -10)
		pwr[e++] = '0';
	i = 0;
	while (tab->ret[i] != '\0')
		tab->ret[i++] = '\0';
	return (pwr);
}

// void	Dbl(t_printf *tab)
// {
// 	int		pwr;
// 	char	*str;
// 	int		sgn;

// 	pwr = 0;
// 	sgn = 0;
// 	str = (char*)malloc(sizeof(char) * 9);
// 	if (tab->e > 1 || tab->e < -1)
// 	{
// 		while (tab->e > 1.000000e+07 || tab->e <= -1.000000e+07)
// 		{
// 			tab->e = tab->e / 10;
// 			pwr++;
// 		}
// 	}
// 	if (tab->e < 1 && tab->e > -1)
// 		while (tab->e < 1000000 && tab->e > -1000000 && pwr-- > -309)
// 			tab->e = tab->e * 10;
// 	tab->c = tab->e;
// 	if (((tab->e * 10) - (tab->c * 10)) > 5)
// 		tab->c += 1;
// 	if (((tab->e * 10) - (tab->c * 10)) < -5)
// 		tab->c -= 1;
// 	while((tab->e >= 10 || tab->e <= -10) && pwr++ > -309)
// 		tab->e = tab->e / 10;
// 	if (tab->c < 0 && tab->c > -1000000 && sgn++ == 0)
// 		tab->c = tab->c * -1;
// 	while (tab->c < 1000000 && tab->c > 0)
// 		tab->c = tab->c * 10;
// 	if(sgn == 1)
// 		tab->c = tab->c * -1;
// 	tab->nb = pwr;
// 	str = Dblonchar(tab, str);
// 	tab->i = 0;
// 	if (tab->nb < 0)
// 		tab->nb = tab->nb * -1;
// 	Intonchar(tab);
// 	tab->ret = ft_strjoin(str, tab->ret);
// }

void	ft_flage(va_list aq, t_printf *tab)
{
	tab->len = 0;
	tab->e = va_arg(aq, double);
	if (tab->e < 0 && tab->e > (-1.797693e+308 - 1.000000e-308))
		tab->len++;
	tab->len += 14;
	tab->ret = (char*)malloc(sizeof(char) * tab->len);
	// Dbl(tab);
}