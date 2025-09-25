/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_short.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 23:11:43 by tarchen           #+#    #+#             */
/*   Updated: 2017/09/06 20:19:48 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_itoa_short(short val, int base, char lu)
{
	char	*buf;
	char	tmp[65];
	int		i;
	short	tmp_val;

	if (!val || (val == SHRT_MIN && base == 10))
		return (ft_strdup(!val ? "0" : "-32768"));
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
