/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:56:25 by maechard          #+#    #+#             */
/*   Updated: 2017/04/13 11:25:18 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		address;

	address = 0;
	while (s1[address] != '\0')
	{
		if (s1[address] != s2[address])
			return ((unsigned char)s1[address] - (unsigned char)s2[address]);
		address++;
	}
	if (s2[address] != '\0')
		return ((unsigned char)s1[address] - (unsigned char)s2[address]);
	return (0);
}
