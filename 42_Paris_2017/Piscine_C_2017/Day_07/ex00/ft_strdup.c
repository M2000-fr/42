/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 19:36:45 by maechard          #+#    #+#             */
/*   Updated: 2017/03/21 20:49:40 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		address;
	char	*dest;

	address = 0;
	while (src[address] != '\0')
		address++;
	dest = malloc(address * sizeof(char));
	if (dest == NULL)
		return (NULL);
	address = 0;
	while (src[address] != '\0')
	{
		dest[address] = src[address];
		address++;
	}
	dest[address] = '\0';
	return (dest);
}
