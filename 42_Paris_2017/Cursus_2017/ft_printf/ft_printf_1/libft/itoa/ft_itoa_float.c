/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 23:11:43 by tarchen           #+#    #+#             */
/*   Updated: 2017/09/07 01:26:38 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_itoa_float(float f, int base, char lu)
{
	int		i;
	char	*res;
	char	buf[32];

	res = ft_itoa_long_long((long long)f, base, lu);
	buf[0] = '.';
	f -= (float)((long long)f);
	if (f < 0)
		f = -f;
	i = 0;
	while (i < 6)
	{
		f *= (float)10;
		buf[++i] = lu ? STR_BASE[(int)f % base] : STR_BASE_MAJ[(int)f % base];
	}
	buf[++i] = 0;
	ft_strjoin_f(&res, buf);
	return (res);
}
