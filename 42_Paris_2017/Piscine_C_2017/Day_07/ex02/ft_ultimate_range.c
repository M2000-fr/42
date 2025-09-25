/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 21:57:08 by maechard          #+#    #+#             */
/*   Updated: 2017/03/25 18:10:12 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		dif;
	int		address;

	address = 0;
	dif = max - min;
	range[0] = NULL;
	if (min >= max)
		return (0);
	if (!(range[0] = (int*)malloc(sizeof(range[0]) * dif)))
		return (0);
	while (min != max)
		range[0][address++] = min++;
	return (dif);
}
