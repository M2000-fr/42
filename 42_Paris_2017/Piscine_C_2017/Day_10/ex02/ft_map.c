/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:29:50 by maechard          #+#    #+#             */
/*   Updated: 2017/03/27 12:42:34 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		address;
	int		*resultat;

	address = 0;
	if (!(resultat = (int*)malloc(sizeof(int) * length)))
		return (NULL);
	while (address < length)
	{
		resultat[address] = f(tab[address]);
		address++;
	}
	return (resultat);
}
