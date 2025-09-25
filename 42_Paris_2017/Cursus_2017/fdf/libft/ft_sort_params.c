/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:16:06 by tarchen           #+#    #+#             */
/*   Updated: 2017/08/05 19:47:54 by Theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		**ft_sort_params(int ac, char **av)
{
	char	*tmp;
	int		is_sort;
	int		i;

	is_sort = 1;
	while (is_sort)
	{
		is_sort = 0;
		i = 0;
		while (++i < ac - 1 && av[i + 1])
			if (ft_strcmp(av[i], av[i + 1]) > 0)
			{
				tmp = av[i];
				av[i] = av[i + 1];
				av[i + 1] = tmp;
				is_sort = 1;
			}
	}
	return (av);
}
