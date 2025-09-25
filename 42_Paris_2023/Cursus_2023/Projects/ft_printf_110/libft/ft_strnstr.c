/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:05:23 by mechard           #+#    #+#             */
/*   Updated: 2023/11/15 11:53:31 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = -1;
	size = 0;
	if (!len && (!big || !little))
		return (0);
	while (little[size] != '\0')
		++size;
	if (size == 0)
		return ((char *)big);
	while (big[++i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (i + j > len)
				return (0);
			if (j == size - 1)
				return ((char *)big + i);
			++j;
		}
	}
	return (0);
}
