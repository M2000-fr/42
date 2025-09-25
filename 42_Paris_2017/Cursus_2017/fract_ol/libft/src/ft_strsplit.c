/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:32:25 by maechard          #+#    #+#             */
/*   Updated: 2014/11/09 15:24:22 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nb_mots(char *s, char c)
{
	int		nb_mots;
	int		a;

	nb_mots = 0;
	a = 0;
	if (!s)
		return (0);
	while (s[a] != '\0')
	{
		while (s[a] == c)
			a++;
		if (s[a] >= 33 && s[a] <= 126)
			nb_mots++;
		while (s[a] != c && s[a] != '\0')
			a++;
	}
	return (nb_mots);
}

int		ft_nb_lettres(char *str, char c)
{
	int		nb;

	nb = 0;
	while (str[nb] != c && str[nb])
		nb++;
	return (nb);
}

void	ft_cp(char *src, char *dest, int length)
{
	int		a;

	a = 0;
	while (a < length)
	{
		dest[a] = src[a];
		if (src[a] == '\n' && src[a - 1] == '\n')
			if (src[a + 1] != '\0')
				dest[a] = '\0';
		a++;
	}
	dest[a] = '\0';
}

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
