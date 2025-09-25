/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:33:49 by tarchen           #+#    #+#             */
/*   Updated: 2016/11/09 18:55:56 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;

	src = (unsigned char*)s;
	while (n--)
	{
		if ((*(unsigned char *)src) == (unsigned char)c)
			return ((void *)src);
		src++;
	}
	return (NULL);
}
