/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 23:11:43 by tarchen           #+#    #+#             */
/*   Updated: 2017/09/06 20:21:55 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_itoa_unsigned_char(unsigned char val, int base, char lu)
{
	char	tmp[65];
	int		i;

	if (!val)
		return (ft_strdup("0"));
	if (base < 2 || base > 36)
		return (NULL);
	i = 37;
	while (val && --i)
	{
		tmp[i] = lu ? STR_BASE[val % base] : STR_BASE_MAJ[val % base];
		val /= base;
	}
	return (ft_strdup(&tmp[i + 1]));
}
