/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 11:13:50 by maechard          #+#    #+#             */
/*   Updated: 2015/03/17 11:13:54 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_replace_char(char const *s, char c_s, char c_r)
{
	char	*str;
	int		i;

	str = (char*)s;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c_s)
			str[i] = c_r;
		++i;
	}
	return (str);
}
