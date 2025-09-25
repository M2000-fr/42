/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:24:24 by maechard          #+#    #+#             */
/*   Updated: 2014/11/08 14:20:05 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_arrcpy(char **arr)
{
	char	**new_arr;
	t_uint	pos;

	if (!(new_arr = (char**)malloc(sizeof(char *) * (ft_arrlen(arr) + 1))))
		return (NULL);
	pos = 0;
	while (arr && arr[pos])
		new_arr[pos] = ft_strdup(arr[pos]), pos++;
	new_arr[pos] = NULL;
	return (new_arr);
}
