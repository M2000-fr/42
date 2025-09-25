/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:27:17 by maechard          #+#    #+#             */
/*   Updated: 2017/04/13 11:26:44 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	address;

	address = 0;
	while (s1[address] != '\0' && address < n)
	{
		if (s1[address] != s2[address])
			return ((unsigned char)s1[address] - (unsigned char)s2[address]);
		address++;
	}
	if (s2[address] != '\0' && address < n)
		return ((unsigned char)s1[address] - (unsigned char)s2[address]);
	return (0);
}
