/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:33:49 by tarchen           #+#    #+#             */
/*   Updated: 2016/11/09 18:57:45 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "./includes/libft.h"

static	void	*ft_memcpy_inter(void *s1, const void *s2, size_t n)
{
	char		*ptr1;
	char		*ptr2;

	if (n == 0 || s1 == s2)
		return (s1);
	ptr1 = (char *)s1;
	ptr2 = (char *)s2;
	while (n--)
	{
		ptr1[n] = ptr2[n];
	}
	return (s1);
}

void			*ft_memmove(void *s1, const void *s2, size_t n)
{
	if (s1 < s2)
		return (ft_memcpy(s1, s2, n));
	if (s1 > s2)
		return (ft_memcpy_inter(s1, s2, n));
	return (s1);
}
