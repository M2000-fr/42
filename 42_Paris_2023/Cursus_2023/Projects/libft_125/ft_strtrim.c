/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:31:12 by mechard           #+#    #+#             */
/*   Updated: 2023/11/15 08:16:41 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*r;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup((char *)s1));
	start = 0;
	end = ft_strlen((char *)s1);
	while (is_in_set(s1[start], set) == 0)
		start++;
	if (start == ft_strlen((char *)s1))
	{
		r = ft_strdup("");
		if (!r)
			return (NULL);
		else
			return (r);
	}
	while (is_in_set(s1[end - 1], set) == 0)
		end--;
	r = ft_substr(s1, start, end - start);
	return (r);
}
