/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:27:32 by maechard          #+#    #+#             */
/*   Updated: 2017/04/28 18:43:55 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_validmap(char *file)
{
	int		a;
	int		j;

	a = 0;
	j = 0;
	while(file[a] != '\0')
	{
		if (file[a] == '\n')
			j++;
		a++;
	}	
	if (a == 20 && j == 4)
		return (1);
	return (0);
}

int		ft_count(char *file)
{
	int		a;
	int		b;
	int		d;

	a = 0;
	b = 0;
	d = 0;
	while (file[a] != '\0')
	{
		if (file[a] == '#')
			d++;
		if (file[a] == '.')
			b++;
		a++;
	}
	if (d == 4 && b == 12)
		return (1);
	return (0);
}

int		ft_link(char *file)
{
	int		link;
	int		a;
	char	b;

	link = 0;
	a = 0;
	b = '#';
	while (file[a] != '\0')
	{
		if (file[a] == b)
		{
			if (file[a + 1] == b && file[a + 1])
				link++;
			if (file[a - 1] == b && file[a - 1])
				link++;
			if (a < 15 && file[a + 5] == b && file[a + 5])
				link++;
			if (a > 4 && file[a - 5] == b && file[a - 5])
				link++;
		}
		a++;
	}
	if (link == 6 || link == 8)
		return (1);
	return (0);
}

int		ft_verif(char **str)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (str[a] != 0)
	{
		if ((b = ft_count(str[a])) == 0)
			return (1);
		if ((b = ft_validmap(str[a])) == 0)
			return (1);
		if ((b = ft_link(str[a])) == 0)
			return (1);
		a++;
	}
	return (0);
}
