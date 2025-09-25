/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whois.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:15:23 by abutet            #+#    #+#             */
/*   Updated: 2025/08/04 15:03:36 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "irc.hpp"

bool Whois::checkArgs()
{
	if (_spltcmd.size() < 2 || _spltcmd[1].empty())
	{
		return (false);
	}
	return (true);
}

void Whois::executeCmd() {
	if (!checkArgs())
	{
		PRINT_ERR(ERROR_PARTER);
		return;
	}
	User* targetU = this->_sInfs->searchUser(_spltcmd[1]);
	if (targetU == NULL)
	{
		_setter->appendTWB((std::string) ":localhost 401 " + _setter->getNick() + " " + _spltcmd[1] + " :No such nick/channel\r\n");
		return;
	}
	_setter->appendTWB((std::string) ":localhost 311 " + _setter->getNick() + " " +
						targetU->getNick() + " " +
						targetU->getUser() + " " +
						targetU->getHost() + " * :" +
						targetU->getReal() + "\r\n" +
						":localhost 318 " + _setter->getNick() + " " +
						targetU->getNick() + " :End of /WHOIS list\r\n");
}
