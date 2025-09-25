/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:30:18 by mechard           #+#    #+#             */
/*   Updated: 2023/11/24 15:02:42 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_nbrstr(char *str, long nbr, size_t len, int isneg)
{
	if (nbr != 0)
		str = malloc(sizeof(char) * (len + 1));
	else
		return (str = ft_strdup("0"));
	if (!str)
		return (0);
	isneg = 0;
	if (nbr < 0)
	{
		isneg++;
		nbr = -nbr;
	}
	str[len] = '\0';
	while (--len)
	{
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (isneg == 1)
		str[0] = '-';
	else
		str[0] = (nbr % 10) + '0';
	return (str);
}

char	*ft_itoa(size_t n)
{
	size_t	len;
	char	*r;
	long	nbr;
	int		isneg;

	nbr = n;
	len = ft_nbrlen(nbr, 10);
	r = 0;
	isneg = 0;
	r = ft_nbrstr(r, nbr, len, isneg);
	if (!r)
		return (0);
	return (r);
}
