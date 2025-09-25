/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_dd_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:10:20 by mechard           #+#    #+#             */
/*   Updated: 2023/08/23 20:34:24 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_count_line(char *map)
{
	int	i;
	int	len;
	int	line;

	i = 0;
	len = 0;
	line = 0;
	while (map[i])
	{
		if (map[i] != '\n')
			len++;
		if (map[i] == '\n')
			line++;
		i++;
	}
	return (line + 1);
}

int	ft_count_len(char *map)
{
	int	i;
	int	len;
	int	line;

	i = 0;
	len = 0;
	line = 0;
	while (map[i])
	{
		if (map[i] != '\n')
			len++;
		if (map[i] == '\n')
			line++;
		i++;
	}
	len /= line;
	return (len + 1);
}

void	ft_count(t_args *arg, char *map)
{
	arg->nb_line = ft_count_line(map);
	arg->len = ft_count_len(map);
}
