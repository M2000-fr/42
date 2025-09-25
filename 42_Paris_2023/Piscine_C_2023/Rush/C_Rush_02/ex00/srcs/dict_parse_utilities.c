/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parse_utilities.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 23:21:56 by mechard           #+#    #+#             */
/*   Updated: 2023/08/20 23:21:58 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ft.h"
#include <stdio.h>
#include <stdlib.h>

int	nb_len_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	return (i);
}

void	print_line_value(char *str)
{
	while (*str >= '0' && *str <= '9')
		str++;
	while (*str == ' ')
		str++;
	str++;
	while (*str == ' ')
		str++;
	ft_putstr(str);
}

char	*get_key(char *dict)
{
	int		i;
	char	*str;

	i = 0;
	while (dict[i] >= '0' && dict[i] <= '9')
		i++;
	str = malloc((i + 1) * sizeof(char));
	i = 0;
	while (dict[i] >= '0' && dict[i] <= '9')
	{
		str[i] = dict[i];
		i++;
	}
	return (str);
}

int	found_key(char *nb, char *dict)
{
	int	nbr;

	if (ft_atoi(nb) > 99)
	{
		if (ft_atoi(nb) < 1000)
		{
			nbr = ft_atoi(nb) / 100;
			if (nbr == ft_atoi(dict))
				return (1);
		}
	}
	if (ft_atoi(nb) == ft_atoi(dict))
		return (1);
	return (0);
}
