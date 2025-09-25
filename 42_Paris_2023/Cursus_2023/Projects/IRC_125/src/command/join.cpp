/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:09:13 by mechard           #+#    #+#             */
/*   Updated: 2025/08/15 14:17:55 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.hpp"

int Join::checkArgs() const
{
    if (_spltcmd.size() < 2 || _spltcmd[1].empty())
        return (_setter->appendTWB(CLT_JOINEA), PRINT_WARNING(WARNING_JOINEA), 1);
    return (0);
}

void Join::executeCmd()
{
    if (checkArgs())
    {
        _setter->appendTWB(CLT_JOINIA);
        PRINT_ERR(ERROR_JOINIA);
        return;
    }
    if (!_setter->isRegis())
    {
        _setter->appendTWB(CLT_JOINUU);
        PRINT_WARNING(WARNING_JOINUU);
        return;
    }
    std::string chanName = this->_spltcmd[1];
    chanName.erase(chanName.find_last_not_of("\r\n") + 1);
    Channel *toConnect = this->_sInfs->getChannelByName(chanName);
    if (toConnect)
    {
        if (toConnect->getAlreadyRegistered(this->_setter) == true)
        {
            _setter->appendTWB(CLT_JOINAC);
            PRINT_WARNING(WARNING_JOINAC);
            return;
        }
        if (toConnect->getNeedInvite() == true)
        {
            if (!toConnect->isInvited(this->_setter))
            {
                _setter->appendTWB(":localhost 473 " + _setter->getNick() + " " + toConnect->getName() + " :Cannot join channel (+i)\r\n");
                _setter->appendTWB(CLT_JOINIO);
                PRINT_WARNING(WARNING_JOINIO);
                return;
            }
        }
        else if (toConnect->getLimitedUsers())
        {
            if (toConnect->getMaxUsers() <= toConnect->getUsersNumber())
            {
                _setter->appendTWB(":localhost 471 " + _setter->getNick() + " " + toConnect->getName() + " :Cannot join channel (+l)\r\n");
                _setter->appendTWB(CLT_JOINCF);
                PRINT_WARNING(WARNING_JOINCF);
                return;
            }
        }
        else if (!toConnect->getPass().empty())
        {
            if (_spltcmd.size() < 3 || toConnect->getPass().compare(_spltcmd[2]))
            {
                _setter->appendTWB(":localhost 475 " + _setter->getNick() + " " + toConnect->getName() + " :Cannot join channel (+k)\r\n");
                _setter->appendTWB(CLT_JOINWP);
                PRINT_WARNING(WARNING_JOINWP);
                return;
            }
        }

        toConnect->addUser(this->_setter);
        _setter->appendTWB(CLT_JOINSU);
        if (toConnect->getBotChannel())
            toConnect->botCmd("!welcome", _setter);
        PRINT_SUCCESS(SUCCESS_JCHAN);
    }
    else if(chanName[0] == '#')
    {
        toConnect = new Channel(chanName, this->_setter, 100, false, false);
        toConnect->addUser(this->_setter);
        toConnect->addOp(this->_setter);
        this->_sInfs->addChannel(toConnect);
        _setter->appendTWB(CLT_JOINSU);
        if (toConnect->getBotChannel())
            toConnect->botCmd("!welcome", _setter);
        PRINT_SUCCESS(SUCCESS_JCRCH);
        PRINT_INFOS(CH_DATA);
    }
    else
    {
        PRINT_ERR(CLT_JOINIA);
        std::cout << BLUE << "Needs a '#' to create a channel" << WHITE << std::endl;
        return;
    }
    _setter->appendTWB(":" + _setter->getPrefix() + " JOIN " + toConnect->getName() + "\r\n");
}
