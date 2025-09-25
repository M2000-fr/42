/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:51:13 by mechard           #+#    #+#             */
/*   Updated: 2023/08/19 15:04:06 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ft.h"

int	input_valid_nb(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || (str[i] > '\n' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' && str[i] != '+')
	{
		if (str[i] == '-')
			return (ft_putstr("Error\n"), 0);
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (ft_putstr("Error\n"), 0);
}

int	input_valid_add(char *str, char *nb)
{
	int	i;

	i = 0;
	while (((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A'
				&& str[i] <= 'Z')) && str[i] != '\n')
		i++;
	if (str[i] != '\n')
		return (ft_putstr("Error\n"), 0);
	if (str[i] == '\n' && input_valid_nb(nb) > 0)
		return (1);
	return (ft_putstr("Error\n"), 0);
}
