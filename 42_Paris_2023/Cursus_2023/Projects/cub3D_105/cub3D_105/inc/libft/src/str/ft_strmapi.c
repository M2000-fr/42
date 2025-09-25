/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:19:28 by mechard           #+#    #+#             */
/*   Updated: 2024/03/04 11:08:10 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*str_new;
	unsigned int	counter;

	str = (char *)s;
	if (str && f)
	{
		counter = 0;
		str_new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
		if (!str_new)
			return (0);
		while (str[counter])
		{
			str_new[counter] = (*f)(counter, str[counter]);
			counter++;
		}
		str_new[counter] = '\0';
		return (str_new);
	}
	return (0);
}
