/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:50:36 by mechard           #+#    #+#             */
/*   Updated: 2023/11/14 14:22:41 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
