/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:05:11 by mechard           #+#    #+#             */
/*   Updated: 2023/08/24 11:38:09 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	add;
	int	add2;

	add = ft_strlen(dest);
	add2 = 0;
	while (src[add2] != '\0')
	{
		dest[add + add2] = src[add2];
		add2++;
	}
	dest[add + add2] = '\0';
	return (dest);
}

int	ft_getlen(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	if (size == 0)
		return (1);
	i = 0;
	len = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);
	len += ft_strlen(sep) * (size - 1);
	return (len + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * ft_getlen(size, strs, sep));
	if (!dest)
		return (NULL);
	dest[0] = 0;
	if (size == 0)
		return (dest);
	while (i < size)
	{
		ft_strcat(dest, strs[i]);
		if (i != size - 1)
			ft_strcat(dest, sep);
		i++;
	}
	dest[ft_strlen(dest)] = 0;
	return (dest);
}
