/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdeln.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:47:41 by mechard           #+#    #+#             */
/*   Updated: 2025/06/04 14:06:57 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strdeln(char *str)
{
	int	i;

	i = 1;
	if (str[ft_strlen(str) - i] == '\n')
	{
		if (str[ft_strlen(str) - i - 1] == '\r')
			i++;
		str[ft_strlen(str) - i] = '\0';
	}
	return (0);
}
