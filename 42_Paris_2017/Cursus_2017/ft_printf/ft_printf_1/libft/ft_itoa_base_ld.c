/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ld.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 06:38:36 by tarchen           #+#    #+#             */
/*   Updated: 2017/09/04 23:37:13 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char			*ft_itoa_base_ld(long val, int base)
{
	char		*buf;
	char		*tmp;
	int			i;
	long		tmp_val;

	if (!val || (val == LONG_MIN && base == 10))
	{
		buf = ft_strdup(!val ? "0" : "-9223372036854775808");
		return (buf);
	}
	if (base < 2 || base > 36)
		return (NULL);
	tmp_val = val;
	if (val < 0)
		val *= -1;
	i = ft_strlen(STR_BASE);
	tmp = try_malloc(sizeof(char) * 65, _FL_);
	while (val && i)
	{
		tmp[i] = STR_BASE[val % base];
		i--;
		val /= base;
	}
	buf = ft_strdup(&tmp[i + 1]);
	ft_strdel(&tmp);
	return (tmp_val < 0 ? ft_strjoin("-", buf) : buf);
}
