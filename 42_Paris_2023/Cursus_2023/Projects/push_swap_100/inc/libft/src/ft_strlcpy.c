/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:45:35 by mechard           #+#    #+#             */
/*   Updated: 2024/03/26 19:22:15 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = -1;
	while (src[++i] && i < size - 1)
		dst[i] = src[i];
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strncpy(int i, int len, const char *str)
{
	char	*dest;
	int		j;

	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (j < len)
	{
		dest[j] = str[i + j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
