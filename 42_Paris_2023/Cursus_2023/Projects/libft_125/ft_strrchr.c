/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:34:54 by mechard           #+#    #+#             */
/*   Updated: 2023/11/15 11:17:54 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	char	*str;
	int		len;
	int		i;

	str = s;
	i = 0;
	len = (int)ft_strlen(str);
	while (i < len)
	{
		i++;
		str++;
	}
	while (i >= 0)
	{
		if (str[0] == (char)c)
			return (str);
		i--;
		str--;
	}
	return (NULL);
}
