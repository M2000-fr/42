/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 19:25:02 by maechard          #+#    #+#             */
/*   Updated: 2017/03/23 17:45:46 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_nb_mots(char *s)
{
	int		nb_mots;
	int		a;

	nb_mots = 0;
	a = 0;
	if (!s)
		return (0);
	while (s[a] != '\0')
	{
		while (s[a] == ' ' || s[a] == '\n' || s[a] == '\t')
			a++;
		if (s[a] >= 33 && s[a] <= 126)
			nb_mots++;
		while (s[a] != ' ' && s[a] != '\n' && s[a] != '\t' && s[a] != '\0')
			a++;
	}
	return (nb_mots);
}

int		ft_nb_lettres(char *str)
{
	int		nb;

	nb = 0;
	while (str[nb] != '\t' && str[nb] != ' ' && str[nb] != '\n' && str[nb])
		nb++;
	return (nb);
}

void	ft_cp(char *src, char *dest, int length)
{
	int		a;

	a = -1;
	while (++a < length)
		dest[a] = src[a];
	dest[a] = '\0';
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		mots;
	int		a;
	int		b;
	int		c;

	mots = ft_nb_mots(str);
	if (!(tab = (char **)malloc(sizeof(char *) * mots + 1)))
		return (NULL);
	a = 0;
	c = -1;
	while (++c < mots)
	{
		while (str[a] == ' ' || str[a] == '\t' || str[a] == '\n')
			a++;
		b = ft_nb_lettres(str + a);
		if (!(tab[c] = (char*)malloc(sizeof(*tab) * (b + 1))))
			return (NULL);
		ft_cp(str + a, tab[c], b);
		a = a + b;
	}
	tab[c] = 0;
	return (tab);
}
