/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:57:50 by mechard           #+#    #+#             */
/*   Updated: 2025/07/29 12:57:50 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.hpp"

int PrivMsg::checkArgs() const
{
	if (_spltcmd.size() < 3)
		return (_setter->appendTWB(CLT_PRIVEA), PRINT_WARNING(WARNING_PRIVEA), 1);

	std::string target = _spltcmd.at(1);
	if (target[0] == '#')
	{
		Channel *_targetC = _sInfs->getChannelByName(target);
		if (!_targetC)
			return (_setter->appendTWB(CLT_CHANNF), PRINT_WARNING(WARNING_CHANNF), 1);
		if (!_targetC->isUserInChannel(_setter))
			return (PRINT_WARNING(WARNING_USERNC), 1);
	}
	else
	{
		User *_targetU = _sInfs->searchUser(target);
		if (!_targetU || !_targetU->isRegis())
			return (_setter->appendTWB(CLT_USERNF), PRINT_WARNING(WARNING_USERNF), 1);
	}
	return (0);
}

void PrivMsg::executeCmd()
{
	if (checkArgs())
		return (_setter->appendTWB(CLT_PRIVIA), PRINT_ERR(ERROR_PRIVIA), (void)_setter);
	std::string target = _spltcmd.at(1);
	std::string content = _spltcmd.at(2);
	unsigned long i = 2;
	while (++i < _spltcmd.size())
		content += " " + _spltcmd.at(i);
	if (target[0] == '#')
	{
		Channel *_targetC = _sInfs->getChannelByName(target);
		if (content[0] == '!' && _targetC->getBotChannel())
		{
			_targetC->botCmd(content, _setter);
			return ;
		}
		std::string msg = ":" + _setter->getPrefix() + " PRIVMSG " + target + " :" + content + "\r\n";
		if (_targetC)
			_targetC->sendAll(msg, _setter);
	}
	else
	{
		std::string msg = ":" + _setter->getPrefix() + " PRIVMSG #" + target + " :" + content + "\r\n";
		User *_targetU = _sInfs->searchUser(target);
		if (_targetU)
			_targetU->appendTWB(msg);
	}
	return;
}
