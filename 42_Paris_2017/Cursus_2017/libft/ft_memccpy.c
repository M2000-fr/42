/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:19:43 by maechard          #+#    #+#             */
/*   Updated: 2017/04/13 11:23:24 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dptr;
	unsigned char	*sptr;

	dptr = (unsigned char *)dest;
	sptr = (unsigned char *)src;
	while (n && *sptr != (unsigned char)c)
	{
		*(dptr++) = *(sptr++);
		n--;
	}
	if (*sptr == (unsigned char)c)
		*dptr = *sptr;
	return (*sptr == (unsigned char)c) ? dptr + 1 : (void *)0;
}
