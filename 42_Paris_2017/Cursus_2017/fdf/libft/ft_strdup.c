/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:33:49 by tarchen           #+#    #+#             */
/*   Updated: 2017/08/31 17:04:28 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./includes/libft.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	size_t	len;

	if (!src)
		return (NULL);
	len = ft_strlen(src) + 1;
	dest = try_malloc(sizeof(char) * len, _FL_);
	ft_strcpy(dest, src);
	return (dest);
}

char	*ft_strndup(const char *src, size_t n)
{
	char	*dest;
	size_t	len;

	if (!src)
		return (NULL);
	len = ft_strlen(src) + 1;
	if (n < len)
		len = n + 1;
	dest = try_malloc(sizeof(char) * len, _FL_);
	ft_strncpy(dest, src, n);
	return (dest);
}
