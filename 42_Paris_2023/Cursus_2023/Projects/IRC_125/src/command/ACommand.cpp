/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  ACommand.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:06:14 by mechard           #+#    #+#             */
/*   Updated: 2025/07/16 13:06:14 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.hpp"

ACommand::ACommand(Server *sInfs, const std::vector<std::string> spltCmd, User *sender) : _sInfs(sInfs), _spltcmd(spltCmd), _setter(sender)
{
    PRINT_METHOD(AC_CONSTRUCT);
}

ACommand::~ACommand()
{
    PRINT_METHOD(AC_DESTRUCTO);
}

std::vector<std::string> ACommand::getSpltCmd()
{
    return this->_spltcmd;
}

void ACommand::printSpltcmd()
{
    for (std::vector<std::string>::const_iterator it = this->_spltcmd.begin();
         it != this->_spltcmd.end();
         ++it)
    {
        std::cout << "[" << *it << "]";
    }
}
