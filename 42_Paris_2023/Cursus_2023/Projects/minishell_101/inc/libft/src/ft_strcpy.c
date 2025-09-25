/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:34:50 by mechard           #+#    #+#             */
/*   Updated: 2024/11/27 12:21:40 by mechard          ###   ########.fr       */
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
