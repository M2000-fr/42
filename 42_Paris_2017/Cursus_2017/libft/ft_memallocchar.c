/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memallocchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:34:07 by maechard          #+#    #+#             */
/*   Updated: 2017/04/27 16:37:00 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memallocchar(size_t size)
{
	char	*dest;
	char	*tmp;

	tmp = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * size)))
		return (0);
	dest = tmp;
	ft_bzero(dest, size);
	return (dest);
}
