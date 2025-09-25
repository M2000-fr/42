/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 19:55:33 by maechard          #+#    #+#             */
/*   Updated: 2017/03/25 18:33:23 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		dif;
	int		address;
	int		*ran;

	address = 0;
	dif = max - min;
	if (min >= max)
		return (0);
	if (!(ran = (int*)malloc(sizeof(ran) * dif)))
		return (ran);
	while (min != max)
	{
		ran[address] = min;
		address++;
		min++;
	}
	ran[address] = '\0';
	return (ran);
}
