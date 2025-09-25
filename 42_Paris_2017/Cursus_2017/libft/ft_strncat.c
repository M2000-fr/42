/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 21:19:58 by maechard          #+#    #+#             */
/*   Updated: 2017/04/13 11:26:26 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, char *src, unsigned int n)
{
	char	*sptr;
	char	*dptr;

	sptr = (char *)src;
	dptr = dest;
	while (*dptr)
		dptr++;
	while (n--)
	{
		if (!(*(dptr++) = *(sptr++)))
			return (dest);
	}
	*dptr = '\0';
	return (dest);
}
