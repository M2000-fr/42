/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:22:11 by mechard           #+#    #+#             */
/*   Updated: 2023/08/24 11:14:17 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	len;
	int	*tab;

	len = max - min;
	if (len < 1)
		return (NULL);
	else
	{
		tab = malloc(sizeof(int) * len);
		if (!tab)
			return (NULL);
		i = 0;
		while (i < len)
		{
			tab[i] = (min + i);
			i++;
		}
	}
	return (tab);
}
