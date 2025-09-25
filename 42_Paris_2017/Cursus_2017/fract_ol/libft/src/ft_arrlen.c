/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:24:24 by maechard          #+#    #+#             */
/*   Updated: 2014/11/08 14:20:05 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_uint	ft_arrlen(char **arr)
{
	t_uint count;

	count = 0;
	while (arr && arr[count])
		++count;
	return (count);
}
