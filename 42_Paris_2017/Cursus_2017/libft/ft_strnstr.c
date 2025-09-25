/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 11:48:12 by maechard          #+#    #+#             */
/*   Updated: 2017/04/13 11:27:18 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t		address;
	size_t		address2;
	size_t		size;

	address = 0;
	size = 0;
	while (to_find[size] != '\0')
		++size;
	if (size == 0)
		return ((char*)str);
	while (str[address] != '\0' && address < len)
	{
		address2 = 0;
		while (str[address + address2] == to_find[address2])
		{
			if (address + address2 > len)
				return (0);
			if (address2 == size - 1)
				return ((char*)str + address);
			++address2;
		}
		++address;
	}
	return (0);
}
