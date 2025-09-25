/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:33:42 by maechard          #+#    #+#             */
/*   Updated: 2017/04/13 11:27:33 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*sptr;
	char	*lptr;

	sptr = (char *)s;
	lptr = (*s == c) ? (char *)s : (char *)0;
	while (*sptr != '\0')
	{
		if (*sptr == c)
			lptr = sptr;
		sptr++;
	}
	if (*sptr == c)
		lptr = sptr;
	return (lptr);
}
