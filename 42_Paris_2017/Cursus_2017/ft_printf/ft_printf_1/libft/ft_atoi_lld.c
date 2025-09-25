/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_lld.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:33:49 by tarchen           #+#    #+#             */
/*   Updated: 2017/09/22 06:17:21 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

unsigned long int		ft_atoi_ulld(const char *str)
{
	unsigned long int	i;
	unsigned long int	nbr;
	unsigned long int	negative;

	i = 0;
	while (!(nbr = 0) && str[i] && !ft_isdigit(str[i]))
		i++;
	negative = (str[i - 1] == '-') ? 1 : 0;
	str[i] == '+' || str[i] == '-' ? 0 : i--;
	while ((str[++i] >= '0') && (str[i] <= '9'))
		nbr = (nbr * 10) + str[i] - '0';
	return (negative == 1 ? -nbr : nbr);
}

long int		ft_atoi_lld(const char *str)
{
	long int	i;
	long int	nbr;
	long int	negative;

	i = 0;
	while (!(nbr = 0) && str[i] && !ft_isdigit(str[i]))
		i++;
	negative = (str[i - 1] == '-') ? 1 : 0;
	str[i] == '+' || str[i] == '-' ? 0 : i--;
	while ((str[++i] >= '0') && (str[i] <= '9'))
		nbr = (nbr * 10) + str[i] - '0';
	return (negative == 1 ? -nbr : nbr);
}
