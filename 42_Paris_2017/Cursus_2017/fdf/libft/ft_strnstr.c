/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:33:49 by tarchen           #+#    #+#             */
/*   Updated: 2016/11/09 17:38:54 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strnstr(char *s1, char *s2, size_t n)
{
	char	*cpy;
	char	*buf;
	size_t	length;

	buf = (char *)(s1 + n);
	length = ft_strlen(s2);
	cpy = (char *)s1;
	if (!length)
		return ((char *)s1);
	while ((cpy = ft_strchr(cpy, *s2)) && cpy <= buf)
	{
		if ((cpy + length <= buf) && !ft_strncmp(cpy, s2, length))
			return (cpy);
		cpy++;
	}
	return (NULL);
}
