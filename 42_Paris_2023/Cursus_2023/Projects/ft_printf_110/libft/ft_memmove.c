/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 00:12:00 by mechard           #+#    #+#             */
/*   Updated: 2023/11/14 17:10:42 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	char	*tmp_dst;
	char	*tmp_src;
	size_t	i;

	if (len == 0 || dst == src)
		return (dst);
	tmp_dst = (char *)dst;
	tmp_src = (char *)src;
	i = 1;
	if (tmp_src < tmp_dst)
	{
		while (i <= len)
		{
			tmp_dst[len - i] = tmp_src[len - i];
			i++;
		}
	}
	else
		while (len--)
			*(tmp_dst++) = *(tmp_src++);
	return (dst);
}
