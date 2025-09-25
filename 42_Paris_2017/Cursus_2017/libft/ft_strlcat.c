/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:03:49 by maechard          #+#    #+#             */
/*   Updated: 2017/04/13 13:31:22 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	slen;
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen((char*)src));
	while (dest[i] && i < size)
		i++;
	slen = i;
	while (src[i - slen] && i < size - 1)
	{
		dest[i] = src[i - slen];
		i++;
	}
	if (slen < size)
		dest[i] = '\0';
	return (slen + ft_strlen((char*)src));
}
