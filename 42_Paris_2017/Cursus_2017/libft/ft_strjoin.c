/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 11:52:39 by maechard          #+#    #+#             */
/*   Updated: 2017/04/14 13:32:27 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		a;

	if (!(s1) && s2)
		return (ft_strdup(s2));
	if (!(s2) && s1)
		return (ft_strdup(s1));
	a = ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1;
	if (!(res = (char*)malloc(sizeof(char) * a)))
		return (0);
	ft_strcpy(res, (char*)s1);
	ft_strcat(res, (char*)s2);
	return (res);
}
