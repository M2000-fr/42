/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_mots.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:56:26 by maechard          #+#    #+#             */
/*   Updated: 2017/04/14 16:45:21 by maechard         ###   ########.fr       */
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
