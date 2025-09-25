/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:24:24 by maechard          #+#    #+#             */
/*   Updated: 2014/11/08 14:20:05 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_arrfree(char ***arr)
{
	int i;

	i = 0;
	while ((*arr)[i])
		free((*arr)[i++]);
	free((*arr)[i]);
	free(*arr);
	*arr = NULL;
}
