/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:30:18 by mechard           #+#    #+#             */
/*   Updated: 2023/11/14 18:51:13 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_nbrstr(char *str, long nbr, int len, int isneg)
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

unsigned int	ft_lennbr(long n)
{
	size_t	len;
	int		isneg;

	len = 0;
	isneg = 0;
	if (n < 0)
	{
		len++;
		isneg++;
		n = -n;
	}
	while (n >= 1)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*r;
	long	nbr;
	int		isneg;

	nbr = n;
	len = ft_lennbr(nbr);
	r = 0;
	isneg = 0;
	r = ft_nbrstr(r, nbr, len, isneg);
	if (!r)
		return (0);
	return (r);
}
