/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dictionary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:22:52 by nrobinso          #+#    #+#             */
/*   Updated: 2023/08/20 23:21:06 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	is_not_printable(char c)
{
	if (c < 32 || c > 126)
	{
		return (1);
	}
	return (0);
}

int	check_dict_line(char *current_char)
{
	int	j;

	j = 0;
	while (current_char[j] != ':' && current_char[j] != ' ')
	{
		if (!is_number(current_char[j]))
			return (1);
		j++;
	}
	while (current_char[j] != ':')
	{
		if (current_char[j] != ' ')
			return (1);
		j++;
	}
	j++;
	while (current_char[j] == ' ')
		j++;
	while (current_char[j] != '\n')
	{
		if (is_not_printable(current_char[j]))
			return (1);
		j++;
	}
	return (0);
}
