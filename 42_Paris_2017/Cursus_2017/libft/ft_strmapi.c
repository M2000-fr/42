/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 20:37:05 by maechard          #+#    #+#             */
/*   Updated: 2017/04/26 19:44:02 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	unsigned int	a;
	char			*r;

	a = 0;
	if (!(s) || !(r = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while ((int)a < (int)ft_strlen(s))
	{
		r[a] = (*f)(a, s[a]);
		a++;
	}
	r[a] = '\0';
	return (r);
}
