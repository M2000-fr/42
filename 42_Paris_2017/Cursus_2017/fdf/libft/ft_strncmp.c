/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:54:56 by tarchen           #+#    #+#             */
/*   Updated: 2016/11/08 11:54:45 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "./includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && *s2 && (*s1 == *s2))
	{
		n--;
		s1++;
		s2++;
	}
	return (n ? (*(unsigned char *)s1) - (*(unsigned char *)s2) : 0);
}
