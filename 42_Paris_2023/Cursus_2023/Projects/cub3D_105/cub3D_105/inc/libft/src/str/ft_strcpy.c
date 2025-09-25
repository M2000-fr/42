/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:34:50 by mechard           #+#    #+#             */
/*   Updated: 2025/04/04 02:40:23 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	add;

	add = 0;
	while (src[add] != '\0')
	{
		dest[add] = src[add];
		add++;
	}
	dest[add] = '\0';
	return (dest);
}

char	*ft_strscpy(char *dest, const char *src, int start)
{
	int	add;

	add = start;
	while (src[add] != '\0')
	{
		dest[add] = src[add];
		add++;
	}
	dest[add] = '\0';
	return (dest);
}

char	*ft_strncpy(char *dest, const char *src, int end)
{
	int	add;

	add = 0;
	while (src[add] != '\0' && add < end)
	{
		dest[add] = src[add];
		add++;
	}
	dest[add] = '\0';
	return (dest);
}

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
