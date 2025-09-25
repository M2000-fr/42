/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 19:36:45 by maechard          #+#    #+#             */
/*   Updated: 2017/04/14 13:35:04 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;

	if (!(dest = malloc(sizeof(char) * (ft_strlen((char*)src) + 1))))
		return (0);
	else
	{
		dest = ft_strcpy(dest, (char*)src);
		return (dest);
	}
}
