/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:20:21 by jealefev          #+#    #+#             */
/*   Updated: 2025/08/04 13:41:33 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.hpp"

bool Quit::checkArgs()
{
    if (_spltcmd.size() != 1)
        return (_setter->appendTWB(CLT_QUITWA), PRINT_WARNING(WARNING_QUITWA), 1);
    if (!this->_sInfs->searchUser(this->_setter->getNick()))
        return (_setter->appendTWB(CLT_QUITNF), PRINT_WARNING(WARNING_QUITNF), 1);
    return (0);
}

void Quit::executeCmd()
{
    if (checkArgs())
    {
        _setter->appendTWB(CLT_QUITIA);
        PRINT_ERR(ERROR_QUITIA);
        return;
    }
    this->_sInfs->disconnectClient(this->_setter->getFd());
}
