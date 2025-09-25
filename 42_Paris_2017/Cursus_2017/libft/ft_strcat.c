/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 12:03:41 by maechard          #+#    #+#             */
/*   Updated: 2017/04/14 12:03:08 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int		address;
	int		address2;

	address = 0;
	address2 = 0;
	while (dest[address] != '\0')
		address++;
	while (src[address2] != '\0')
	{
		dest[address] = src[address2];
		address++;
		address2++;
	}
	dest[address] = '\0';
	return (dest);
}
