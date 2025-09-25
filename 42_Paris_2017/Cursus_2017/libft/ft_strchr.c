/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 14:29:49 by maechard          #+#    #+#             */
/*   Updated: 2017/04/13 11:24:55 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		a;

	a = 0;
	while (s[a] != '\0')
	{
		if (s[a] == (const char)c)
			return ((char*)s + a);
		a++;
	}
	if (c == '\0' && s[a] == '\0')
		return ((char*)s + a);
	return (0);
}
