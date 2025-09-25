/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:16:00 by maechard          #+#    #+#             */
/*   Updated: 2017/04/13 11:28:12 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		address;
	int		address2;
	int		size;

	address = 0;
	size = 0;
	while (to_find[size] != '\0')
		size++;
	if (size == 0)
		return ((char*)str);
	while (str[address] != '\0')
	{
		address2 = 0;
		while (str[address + address2] == to_find[address2])
		{
			if (address2 == size - 1)
				return ((char*)str + address);
			address2++;
		}
		address++;
	}
	return (0);
}
