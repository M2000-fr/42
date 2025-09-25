/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 20:47:13 by maechard          #+#    #+#             */
/*   Updated: 2017/04/14 11:42:32 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(const char *s1, const char *s2)
{
	int		address;

	address = 0;
	if (!(s1) || !(s2))
		return (0);
	while (s1[address] != '\0')
	{
		if (s1[address] != s2[address])
			return (0);
		address++;
	}
	if (s2[address] != '\0')
		return (0);
	return (1);
}
