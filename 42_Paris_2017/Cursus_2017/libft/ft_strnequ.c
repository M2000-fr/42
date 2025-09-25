/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 20:53:53 by maechard          #+#    #+#             */
/*   Updated: 2017/04/13 21:08:57 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	if (!s1 || !s2)
		return (0);
	while ((s1[a] || s2[a]) && a < n)
	{
		if (s1[a] != s2[a] || !s1[a])
			return (0);
		a++;
	}
	return (1);
}
