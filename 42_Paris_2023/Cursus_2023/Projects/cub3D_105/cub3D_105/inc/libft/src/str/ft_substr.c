/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:05:33 by mechard           #+#    #+#             */
/*   Updated: 2024/12/30 12:31:11 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen((char *)s))
		return (ft_strdup("\0"));
	if ((size_t)start + len > ft_strlen((char *)s))
		j = ft_strlen((char *)s) - start;
	if ((size_t)start + len <= ft_strlen((char *)s))
		j = len;
	str = malloc(sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
