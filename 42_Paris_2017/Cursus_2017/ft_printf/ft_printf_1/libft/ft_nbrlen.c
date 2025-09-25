/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 17:22:39 by tarchen           #+#    #+#             */
/*   Updated: 2018/01/14 19:01:33 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

// int				ft_nbrlen(int nbr)
// {
// 	char		*in_string;
// 	int			res;
//
// 	in_string = ft_itoa(nbr);
// 	res = ft_strlen(in_string);
// 	ft_strdel(&in_string);
// 	return (res);
// }

int				ft_nbrlen(int nbr)
{
	int			res;

	res = 0;
	while (nbr)
	{
		res++;
		nbr /= 10;
	}
	return (res);
}
