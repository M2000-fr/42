/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_intmax_t.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 23:11:43 by tarchen           #+#    #+#             */
/*   Updated: 2017/09/06 19:52:57 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_itoa_intmax_t(intmax_t val, int base, char lu)
{
	char		*buf;
	char		tmp[65];
	int			i;
	intmax_t	tmp_val;

	if (!val || (val == LLONG_MIN && base == 10))
		return (ft_strdup(!val ? "0" : "-9223372036854775808"));
	if (base < 2 || base > 36)
		return (NULL);
	tmp_val = val;
	if (val < 0)
		val *= -1;
	i = 37;
	while (val && --i)
	{
		tmp[i] = lu ? STR_BASE[val % base] : STR_BASE_MAJ[val % base];
		val /= base;
	}
	buf = ft_strdup(&tmp[i]);
	return (tmp_val < 0 ? ft_strjoin("-", buf) : buf);
}
