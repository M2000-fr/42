/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:06:36 by tarchen           #+#    #+#             */
/*   Updated: 2017/02/19 16:26:11 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int	intlen(int value)
{
	int		len;

	len = 0;
	if (value < 0)
		len++;
	while (value)
	{
		len++;
		value /= 10;
	}
	return (len);
}

static char	*int_max(void)
{
	char	*buf;

	buf = ft_strnew(intlen(-2147483648) + 1);
	ft_strcpy(buf, "-2147483648");
	return (buf);
}

char		*ft_itoa(int n)
{
	char	*buf;
	int		j;

	if (n == -2147483648)
		return (int_max());
	buf = ft_strnew(intlen(n) + 1);
	j = intlen(n) - 1;
	if (buf)
	{
		if (n < 0)
		{
			buf[0] = '-';
			n *= -1;
		}
		if (n == 0)
			*buf = '0';
		while (n > 0)
		{
			buf[j] = '0' + (n % 10);
			n /= 10;
			j--;
		}
	}
	return (buf);
}
