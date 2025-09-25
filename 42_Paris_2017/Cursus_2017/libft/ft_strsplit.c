/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:37:54 by maechard          #+#    #+#             */
/*   Updated: 2017/04/14 16:44:50 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *str, char c)
{
	char	**tab;
	int		mots;
	int		a;
	int		b;
	int		d;

	mots = ft_nb_mots(((char*)str), c);
	if (!(tab = (char **)malloc(sizeof(char *) * mots + 1)))
		return (NULL);
	a = 0;
	d = -1;
	while (++d < mots)
	{
		while (str[a] == c)
			a++;
		b = ft_nb_lettres(((char*)str + a), c);
		if (!(tab[d] = (char*)malloc(sizeof(*tab) * (b + 1))))
			return (NULL);
		ft_cp((char*)str + a, tab[d], b);
		a = a + b;
	}
	tab[d] = 0;
	return (tab);
}
