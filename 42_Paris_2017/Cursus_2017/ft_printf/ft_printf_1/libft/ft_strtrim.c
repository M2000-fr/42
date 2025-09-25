/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:54:06 by tarchen           #+#    #+#             */
/*   Updated: 2016/11/09 18:42:40 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdlib.h>

static int	ft_find_blank(int c)
{
	return ((c == ' ' || c == '\t' || c == '\n') ? 1 : 0);
}

char		*ft_strtrim(char const *s)
{
	char	*new_str;
	size_t	i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	new_str = ft_strnew(ft_strlen(s));
	if (!new_str)
		return (NULL);
	while (i < ft_strlen(s))
	{
		if (!j && ft_find_blank(s[i]))
			i++;
		else
			new_str[j++] = s[i++];
	}
	while (ft_find_blank(new_str[--j]))
		new_str[j] = '\0';
	return (new_str);
}
