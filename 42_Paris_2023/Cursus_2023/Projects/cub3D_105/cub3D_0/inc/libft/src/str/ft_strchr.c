/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:34:29 by mechard           #+#    #+#             */
/*   Updated: 2025/04/04 02:29:04 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == c % 256)
			return (s + i);
	if (c == '\0' && s[i] == '\0')
		return (s + i);
	return (0);
}

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
