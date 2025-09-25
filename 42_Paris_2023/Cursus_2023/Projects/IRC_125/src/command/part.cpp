/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:23:49 by jealefev          #+#    #+#             */
/*   Updated: 2025/08/04 15:45:25 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.hpp" // quitte un channel

bool Part::checkArgs()
{
    if (this->_spltcmd.size() < 2)
    {
        PRINT_WARNING(WARNING_PARTWA);
        return false;
    }
    this->_target = this->_sInfs->getChannelByName(this->_spltcmd[1]);
    if (!this->_target)
    {
        PRINT_WARNING(WARNING_PARTCN);
        return false;
    }
    else if (this->_target->isUserInChannel(this->_setter) == false)
    {
        PRINT_WARNING(WARNING_PARTUN);
        return false;
    }
    return true;
}

void Part::executeCmd()
{
    std::string reason = ":" + _setter->getPrefix() + " PART " + _target->getName();
    if (_spltcmd.size() > 2 && !_spltcmd[2].empty())
    {
        reason += " :" + _spltcmd[2];
    }
    reason += "\r\n";

    _target->sendAll(reason);
    this->_target->removeOp(this->_setter);
    this->_target->removeUser(this->_setter);
    PRINT_SUCCESS(SUCCESS_PARWR);
    if (_target->getUsers().empty()) {
		std::list<Channel*>& allChannels = _sInfs->getChannels();
		allChannels.remove(_target);
		delete _target;
	}
}

Part::Part(Server *sInfs, std::vector<std::string> spltCmd, User *sender) : ACommand(sInfs, spltCmd, sender)
{
    if (checkArgs() == true)
        executeCmd();
    else
        PRINT_ERR(ERROR_PARTER);
}
