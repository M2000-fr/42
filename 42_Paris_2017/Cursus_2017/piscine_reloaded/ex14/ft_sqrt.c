/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:06:44 by maechard          #+#    #+#             */
/*   Updated: 2017/04/17 13:20:56 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		ft_sqrt(int nb)
{
	int		a;

	a = 1;
	if (nb <= 0)
		return (0);
	while (a < 46342)
	{
		if ((a * a) == nb)
			return (a);
		a++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		a;

	a = 1;
	while (a < ac)
		printf("racine carre = %d\n", ft_sqrt(ft_atoi(av[a++])));
	return (0);
}
