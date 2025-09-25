/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:54:55 by mechard           #+#    #+#             */
/*   Updated: 2023/08/23 21:02:50 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_check(char *str)
{
	int		fd;
	char	*path;

	path = "./maps/";
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		str = ft_strcat(path, str);
		fd = open(str, O_RDONLY);
		if (fd == -1)
			return (-1);
	}
	return (fd);
}

int	ft_check_map(t_args *arg, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == arg->obst || map[i][j] == arg->vide)
			j++;
		i++;
		if (j != arg->len - 1)
			return (-1);
	}
	if (i < arg->nb_line - 1)
		return (-1);
	return (0);
}
