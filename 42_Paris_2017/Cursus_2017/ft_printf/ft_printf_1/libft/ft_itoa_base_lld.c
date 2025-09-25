/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_lld.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 16:26:25 by tarchen           #+#    #+#             */
/*   Updated: 2017/10/11 03:44:32 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char			*ft_itoa_base_lld(long long val, int base)
{
	char		*buf;
	char		*tmp;
	int			i;
	long long	tmp_val;

	if (!val || val == LONG_MIN)
		return (ft_strdup(!val ? "0" : "-9223372036854775808"));
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
