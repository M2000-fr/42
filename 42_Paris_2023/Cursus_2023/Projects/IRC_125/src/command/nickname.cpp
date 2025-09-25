/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nickname.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:09:13 by mechard           #+#    #+#             */
/*   Updated: 2025/07/24 15:09:13 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.hpp"

int Nick::checkArgs() const
{
	if (_spltcmd.size() != 2 || _spltcmd[1].empty())
		return (_setter->appendTWB(CLT_NICKWA), PRINT_WARNING(WARNING_NICKWA), 1);
	User *research = _sInfs->searchUser(_spltcmd[1]);
	if (research != NULL)
	{
		std::string msg = ":" + _setter->getPrefix() + " 433 * " + _spltcmd[1] + " :Nickname is already used\r\n";
		_setter->appendTWB(msg);
		return (_setter->appendTWB(CLT_NICKUS), PRINT_WARNING(WARNING_NICKUS), 1);
	}
	return (0);
}

void Nick::executeCmd()
{
	if (checkArgs())
		return (_setter->appendTWB(CLT_NICKIA), PRINT_ERR(ERROR_NICKIA), (void)_setter);
	PRINT_DEBUG(DEBUG_NICK);
	_setter->setNick(_spltcmd[1]);
	_setter->setHasNick(true);
	_setter->registration();
}