/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:29:50 by maechard          #+#    #+#             */
/*   Updated: 2017/04/27 19:51:43 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char *s, char (*f)(char))
{
	int		a;
	char	*r;

	a = 0;
	if (!(s) || !(r = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (a < (int)ft_strlen(s))
	{
		r[a] = (*f)(s[a]);
		a++;
	}
	r[a] = '\0';
	return (r);
}
