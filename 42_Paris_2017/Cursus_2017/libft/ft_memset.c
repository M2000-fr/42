/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:33:34 by maechard          #+#    #+#             */
/*   Updated: 2017/04/13 11:24:23 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t			a;
	unsigned char	*tmp;
	unsigned char	n;

	tmp = (unsigned char*)str;
	n = (unsigned char)c;
	a = 0;
	while (a < len)
		tmp[a++] = n;
	str = (void*)tmp;
	return (str);
}
