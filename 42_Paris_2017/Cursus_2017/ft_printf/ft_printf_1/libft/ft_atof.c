/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:24:44 by tarchen           #+#    #+#             */
/*   Updated: 2017/09/08 05:25:18 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

float		convert(char *str, float mult)
{
	int		i;
	float	dec;
	float	ret;

	dec = 0;
	ret = 0;
	i = -1;
	while (str[++i] && str[i] != '.')
	{
		ret += str[i] - '0';
		if (str[i + 1] && str[i + 1] != '.')
			ret *= 10;
	}
	if (!str[i])
		return (ret);
	while (str[++i])
	{
		dec += str[i] - '0';
		if (str[i + 1] && str[i + 1] != '.')
			dec *= 10;
	}
	return (ret + (dec / mult));
}

float		ft_atof(char *str)
{
	int		power;
	float	mult;
	float	ret;
	int		neg;

	mult = 1;
	neg = 1;
	if (str[0] == '-')
	{
		neg = -1;
		str = &str[1];
	}
	power = ((ft_strlen(str) - ft_strfind(str, '.')));
	while (--power)
		mult *= 10;
	ret = convert(str, mult);
	return (ret * neg);
}
