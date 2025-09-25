/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:57:02 by mechard           #+#    #+#             */
/*   Updated: 2025/07/15 12:57:02 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.hpp"

int g_flag;

int main(int ac, char **av)
{
	int port;

	g_flag = 1;
	port = ft_checkarg(ac, av);
	if (port == -1)
		return (1);
	Server server(port, av[2]);
	PRINT_INFOS(SERVER_INFOS);
	if (server.start())
		return (PRINT_END(SUCCESS_END), 0);
	return (PRINT_END(FAILED_END), 1);
}
