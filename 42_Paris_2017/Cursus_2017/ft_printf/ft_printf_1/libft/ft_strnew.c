/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:15:27 by tarchen           #+#    #+#             */
/*   Updated: 2017/07/28 07:42:30 by Theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./includes/libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = try_malloc(sizeof(char) * (size + 1), _FL_);
	if (!str)
		return (NULL);
	return (str);
}
