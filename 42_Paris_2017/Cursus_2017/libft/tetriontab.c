/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriontab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 14:07:31 by maechard          #+#    #+#             */
/*   Updated: 2017/04/28 18:05:46 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tetriontab(char *str, char **tab)
{
	int		a;
	int		b;
	int		c;

	if (!(tab = (char **)malloc(sizeof(char *) * ft_nbpcs(str) + 1)))
		return (NULL);
	a = 0;
	c = 0;
	while (c < ft_nbpcs(str))
	{
		b = 21;
		if (!(tab[c] = (char*)malloc(sizeof(*tab) * (b + 1))))
			return (NULL);
		ft_cp(str + a, tab[c], b);
		a = a + b;
		c++;
	}
	tab[c] = 0;
	return (tab);
}
