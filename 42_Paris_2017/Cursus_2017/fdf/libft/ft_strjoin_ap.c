/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_ap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 03:50:39 by tarchen           #+#    #+#             */
/*   Updated: 2017/08/17 03:52:01 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "stdarg.h"

char		*ft_strjoin_ap(int nb_str, ...)
{
	va_list	ap;
	char	*res;
	char	*str;
	char	*tmp;

	va_start(ap, nb_str);
	res = NULL;
	str = NULL;
	while (nb_str--)
	{
		if ((str = va_arg(ap, char *)))
		{
			if (!str)
				continue ;
			if (!res)
				res = ft_strdup(str);
			else
			{
				tmp = ft_strjoin(res, str);
				ft_strdel(&res);
				res = ft_strdup(tmp);
			}
		}
	}
	va_end(ap);
	return (res);
}
