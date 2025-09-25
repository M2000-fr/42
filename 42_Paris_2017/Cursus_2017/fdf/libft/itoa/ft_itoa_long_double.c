/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long_double.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 23:11:43 by tarchen           #+#    #+#             */
/*   Updated: 2017/09/06 20:20:07 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_itoa_long_double(long double f, int base, char lu)
{
	int		i;
	char	*res;
	char	buf[64];

	res = ft_itoa_long_long((long long)f, base, lu);
	buf[0] = '.';
	f -= (long double)((long long)f);
	if (f < 0)
		f = -f;
	i = 0;
	while (i < 15)
	{
		f *= (long double)10;
		buf[++i] = lu ? STR_BASE[(int)f % base] : STR_BASE_MAJ[(int)f % base];
	}
	buf[++i] = 0;
	ft_strjoin_f(&res, buf);
	return (res);
}