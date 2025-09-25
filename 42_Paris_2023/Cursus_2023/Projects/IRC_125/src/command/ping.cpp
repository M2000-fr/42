/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:15:23 by abutet            #+#    #+#             */
/*   Updated: 2025/08/04 14:22:22 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "irc.hpp"

bool Ping::checkArgs()
{
	if (_spltcmd.size() < 2)
	{
		std::string msg461 = ":localhost 461 " + this->_setter->getNick() + " " + this->_spltcmd[0] + " :Not enough parameters\r\n";
		this->_setter->appendTWB(msg461);
		return (false);
	}
	return (true);
}

void Ping::executeCmd() {
	if (!checkArgs())
	{
		PRINT_ERR(ERROR_PARTER);
		return;
	}
	std::string msgpong = "PONG " + _spltcmd[1] + "\r\n";
	_setter->appendTWB(msgpong);
}
