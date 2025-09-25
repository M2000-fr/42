/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invite.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:19:40 by jealefev          #+#    #+#             */
/*   Updated: 2025/08/13 11:29:12 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.hpp"

Invite::Invite(Server *sInfs, std::vector<std::string> spltCmd, User *setter) : ACommand(sInfs, spltCmd, setter)
{
    if (this->checkArgsInvite() == false)
    {
        _setter->appendTWB(CLT_PASSWA);
        PRINT_ERR(ERROR_INVTIA);
        return;
    }
    this->_channel->setNeedInvite(true);
    this->executeCmd();
}

bool Invite::checkArgsInvite()
{
    if (this->_spltcmd.size() != 3)
        return (_setter->appendTWB(CLT_INVTWA), PRINT_WARNING(WARNING_INVTWA), false);
    this->_channel = this->_sInfs->getChannelByName(this->_spltcmd[2]);
    if (!this->_channel)
        return (_setter->appendTWB(CLT_INVTUC), PRINT_WARNING(WARNING_INVTUC), false);
    else if (this->_channel->getNeedInvite() == false)
        return (_setter->appendTWB(CLT_INVTNI), PRINT_WARNING(WARNING_INVTNI), false);
    this->_target = this->_sInfs->searchUser(this->_spltcmd[1]);
    if (!this->_target)
        return (_setter->appendTWB(CLT_INVTSN), PRINT_WARNING(WARNING_INVTSN), false);
    else if (this->_channel->getAlreadyRegistered(this->_target) == true)
        return (_setter->appendTWB(CLT_INVTAR), PRINT_WARNING(WARNING_INVTAR), false);
    else if (this->_channel->isInvited(this->_target) == true)
        return (_setter->appendTWB(CLT_INVTAI), PRINT_WARNING(WARNING_INVTAI), false);
    else if (this->_channel->isOp(this->_setter) == false)
        return (_setter->appendTWB(CLT_INVTOP), PRINT_WARNING(WARNING_INVTOP), false);
    return true;
}

void Invite::executeCmd()
{
    PRINT_SUCCESS(SUCCESS_INVIT);
    _setter->appendTWB(CLT_INVTSU);
    this->_channel->addInvited(this->_target);
}
