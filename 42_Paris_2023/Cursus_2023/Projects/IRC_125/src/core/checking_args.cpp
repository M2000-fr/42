/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:56:45 by mechard           #+#    #+#             */
/*   Updated: 2025/07/16 13:56:45 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.hpp"

/* Checking of "port" argument */

int ft_checkport(char *str)
{
	int port;

	for (size_t i = 0; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (PRINT_ERR(ERROR_INVPOR), -1);
	}
	port = strtol(str, NULL, 10);
	if (errno == 34)
		return (-1);
	if (port < 0 || port > 65535)
		return (PRINT_ERR(ERROR_ORAPOR), -1);
	return (port);
}

/* Checking of "pass" argument */

int ft_checkpass(char *str)
{
	for (size_t i = 0; str[i]; i++)
	{
		if (!isprint(str[i]))
			return (PRINT_ERR(ERROR_INVPOR), -1);
	}
	return (0);
}

/* General checking */

long ft_checkarg(int ac, char **av)
{
	int port;

	if (ac != 3)
		return (PRINT_ERR(ERROR_NBARGS), -1);
	if (!av[1][0] || !av[2][0])
		return (PRINT_ERR(ERROR_INVARG), -1);
	if ((port = ft_checkport(av[1])) == -1 || ft_checkpass(av[2]))
		return (-1);
	return (port);
}
