/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:40:55 by mechard           #+#    #+#             */
/*   Updated: 2025/08/04 12:11:04 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.hpp"

int Pass::checkArgs() const
{
    if (_spltcmd.size() != 2)
        return (_setter->appendTWB(CLT_PASSWA), PRINT_WARNING(WARNING_PASSWA), 1);
    else if (_setter->getHasPass())
        return (_setter->appendTWB(CLT_PASSAS), PRINT_WARNING(WARNING_PASSAS), 1);
    else if (strcmp(_spltcmd[1].c_str(), (_sInfs->getPassword()).c_str()))
        return (_setter->appendTWB(CLT_PASSWP), PRINT_WARNING(WARNING_PASSWP), 1);
    return (0);
}

void Pass::executeCmd()
{
    if (checkArgs())
    {
        _setter->appendTWB(CLT_PASSIA); PRINT_ERR(ERROR_PASSIA); return ;
    }
    this->_setter->setHasPass(true);
    _setter->registration();
}
