/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Theo <Theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:02:03 by Theo              #+#    #+#             */
/*   Updated: 2017/08/19 04:14:21 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*ft_strrev(char *src)
{
	char	*dest;
	int		len;
	int		i;

	len = ft_strlen(src);
	i = -1;
	dest = try_malloc(sizeof(char) * (len + 1), _FL_);
	dest[len] = '\0';
	while (src[i + 1])
		dest[--len] = src[++i];
	return (dest);
}
