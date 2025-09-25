/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:10:59 by mechard           #+#    #+#             */
/*   Updated: 2023/08/23 22:53:06 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int ac, char **av)
{
	int		fd;
	int		i;
	t_args	*arg;
	char	**map;

	i = 0;
	while (i < ac - 1)
	{
		fd = ft_check(av[i + 1]);
		if (fd == -1)
			return (0);
		arg = malloc(sizeof(t_args) * 1);
		map = ft_split_map(arg, fd);
		if (!map)
			return (ft_putstr_fd(1, "map error"), 0);
		ft_reso_bsq(arg, map);
		i++;
	}
	free(arg);
	free(map);
	return (0);
}
