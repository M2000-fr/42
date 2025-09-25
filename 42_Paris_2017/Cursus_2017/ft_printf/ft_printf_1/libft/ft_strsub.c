/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:53:10 by tarchen           #+#    #+#             */
/*   Updated: 2017/09/26 23:42:47 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		length;
	char		*out;

	if (s == NULL)
		return (NULL);
	length = ft_strlen(s);
	out = NULL;
	if ((start + len) <= length)
	{
		out = try_malloc(sizeof(char) * (len + 1), _FL_);
		if (out)
		{
			out = ft_strncpy(out, s + start, len);
			out[len] = '\0';
		}
	}
	return (out);
}
