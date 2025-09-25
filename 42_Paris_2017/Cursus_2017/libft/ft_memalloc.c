/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:06:21 by maechard          #+#    #+#             */
/*   Updated: 2017/04/27 16:33:11 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*dest;
	char	*tmp;

	tmp = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * size)))
		return (0);
	dest = (void*)tmp;
	ft_bzero(dest, size);
	return (dest);
}
