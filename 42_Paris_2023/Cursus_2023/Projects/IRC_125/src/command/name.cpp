/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:09:13 by mechard           #+#    #+#             */
/*   Updated: 2025/08/04 13:36:53 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.hpp"

int Name::checkArgs() const
{
	if (_spltcmd.size() < 5 || _spltcmd[1].empty() || _spltcmd[2].empty() || _spltcmd[3].empty() || _spltcmd[4].empty())
		return (_setter->appendTWB(CLT_NAMEWA), PRINT_WARNING(WARNING_NAMEWA), 1);
	if (!_setter->getReal().empty())
		return (_setter->appendTWB(CLT_NAMEAS), PRINT_WARNING(WARNING_NAMEAS), 1);
	return (0);
}

void Name::executeCmd()
{
	if (checkArgs())
	{
		_setter->appendTWB(CLT_NAMEIA),
		PRINT_ERR(ERROR_NAMEIA);
		return ;
	}
	_setter->setUser(_spltcmd[1]);
	_setter->setHasUser(true);
	_setter->setReal(_spltcmd[4]);
	_setter->registration();
}

