/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:41:41 by mechard           #+#    #+#             */
/*   Updated: 2025/08/13 12:07:45 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.hpp"

// /topic <#channel> <message>
// Change le topic (sujet) du channel. <#channel> est facultatif si vous êtes sur le salon en question

bool Topic::checkArgs()
{

    if (this->_spltcmd.size() < 3)
        return (_setter->appendTWB(CLT_TOPIWA), PRINT_WARNING(WARNING_TOPIWA), false);
    this->_channel = this->_sInfs->getChannelByName(this->_spltcmd[1]);
    if (!this->_channel)
        return (_setter->appendTWB(CLT_TOPINC), PRINT_WARNING(WARNING_TOPINC), false);
    else if (this->_channel->isOp(this->_setter) == false && this->_channel->getProtectTopic())
        return (_setter->appendTWB(CLT_TOPINO), PRINT_WARNING(WARNING_TOPINO), false);
    else if (this->_spltcmd[2].empty() == true)
        return (_setter->appendTWB(CLT_TOPINT), PRINT_WARNING(WARNING_TOPINT), false);
    return true;
}

Topic::Topic(Server *sInfs, std::vector<std::string> spltCmd, User *sender) : ACommand(sInfs, spltCmd, sender)
{
    if (this->checkArgs() == false)
    {
        _setter->appendTWB(CLT_TOPIER),
        PRINT_ERR(ERROR_TOPIER);
        return;
    }
    this->executeCmd();
}

void Topic::executeCmd()
{
    this->_channel->setTopic(this->_spltcmd[2]);
    this->_channel->sendAll(":" + this->_setter->getPrefix() + " TOPIC " + this->_channel->getName() + " :" + this->_spltcmd[2] + "\r\n");
    PRINT_SUCCESS(SUCCESS_TOPIC);
}
