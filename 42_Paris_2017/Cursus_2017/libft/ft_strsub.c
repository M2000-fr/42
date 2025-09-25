/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 21:11:49 by maechard          #+#    #+#             */
/*   Updated: 2017/04/14 11:43:06 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	a;

	a = start;
	if (!(s) || !(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (a < (len + start))
	{
		dest[a - start] = (char)s[a];
		a++;
	}
	dest[a - start] = '\0';
	return (dest);
}
