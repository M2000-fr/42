/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:04:13 by ketrevis          #+#    #+#             */
/*   Updated: 2023/08/20 23:21:34 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ft.h"
#include <fcntl.h>
#include <stdio.h>

char	**check_main_args(int ac, char **av, char **input)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		*input = av[1];
		return (split_file("./dicts/numbers.dict"));
	}
	else if (ac == 3)
	{
		while (is_number(av[1][i]) > 0)
			i++;
		if (av[1][i] == '\0')
		{
			*input = av[1];
			return (split_file(av[2]));
		}
		else
			*input = av[2];
		return (split_file(av[1]));
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	**dict;
	char	*input;

	dict = check_main_args(argc, argv, &input);
	if (dict == 0)
		return (ft_putstr("Error\n"), 0);
	parse_file(input, dict);
	return (0);
}
