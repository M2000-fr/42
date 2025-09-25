/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:04:47 by maechard          #+#    #+#             */
/*   Updated: 2017/04/28 18:05:41 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cp(char *src, char *dest, int length)
{
	int		a;

	a = 0;
	while (a < length)
	{
		dest[a] = src[a];
		if (src[a] == '\n' && src[a - 1] == '\n')
			if (src[a + 1] != '\0')
				dest[a] = '\0';
		a++;
	}
	dest[a] = '\0';
}
