/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u_up.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 16:26:25 by tarchen           #+#    #+#             */
/*   Updated: 2017/08/31 15:20:15 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char			*ft_itoa_base_u_up(unsigned int val, int base)
{
	char		*buf;
	char		*tmp;
	int			i;

	if (!val)
	{
		buf = ft_strdup("0");
		return (buf);
	}
	if (base < 2 || base > 36)
		return (NULL);
	i = ft_strlen(STR_BASE_MAJ);
	tmp = try_malloc(sizeof(char) * 65, _FL_);
	while (val && i)
	{
		tmp[i] = STR_BASE_MAJ[val % base];
		i--;
		val /= base;
	}
	buf = ft_strdup(&tmp[i + 1]);
	ft_strdel(&tmp);
	return (buf);
}
