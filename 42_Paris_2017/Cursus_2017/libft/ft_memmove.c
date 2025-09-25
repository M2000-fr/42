/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:31:22 by maechard          #+#    #+#             */
/*   Updated: 2017/04/13 16:15:13 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dptr;
	char	*sptr;
	char	*tptr;

	if (!(tptr = (char*)malloc(sizeof(char) * n)))
		return ((void *)dest);
	dptr = (char *)dest;
	sptr = (char *)src;
	i = 0;
	while (i++ < n)
		*(tptr++) = *(sptr++);
	i = 0;
	tptr -= n;
	while (i++ < n)
		*(dptr++) = *(tptr++);
	return ((void *)dest);
}
