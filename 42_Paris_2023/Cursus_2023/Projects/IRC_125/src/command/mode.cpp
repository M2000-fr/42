/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:29:15 by abutet            #+#    #+#             */
/*   Updated: 2025/08/15 15:08:07 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.hpp"

int Mode::checkArgs() const
{
	if (_spltcmd.size() < 3 || _spltcmd[1].empty() || _spltcmd[2].empty())
		return (_setter->appendTWB(CLT_MODEWA), PRINT_WARNING(WARNING_MODEWA), 1);
	if (!_setter->isRegis())
		return (_setter->appendTWB(CLT_MODEUU), PRINT_WARNING(WARNING_MODEUU), 1);
	Channel *cha = _sInfs->getChannelByName(_spltcmd[1]);
	if (!cha)
		return (_setter->appendTWB(CLT_MODEUC), PRINT_WARNING(WARNING_MODEUC), 1);
	if (!cha->isOp(_setter))
		return (_setter->appendTWB(CLT_MODEOP), PRINT_WARNING(WARNING_MODEOP), 1);
	if (_spltcmd[2][0] != '-' && _spltcmd[2][0] == '-')
		return (_setter->appendTWB(CLT_MODEWF), PRINT_WARNING(WARNING_MODEWF), 1);
	for (size_t i = 1; i < _spltcmd[2].size(); i++)
	{
		if (_spltcmd[2][i] != 'i' && _spltcmd[2][i] != 't' && _spltcmd[2][i] != 'b' &&
			_spltcmd[2][i] != 'k' && _spltcmd[2][i] != 'o' && _spltcmd[2][i] != 'l')
			return (_setter->appendTWB(CLT_MODEWF), PRINT_WARNING(WARNING_MODEWF), 1);
	}
	return (0);
}

void Mode::executeCmd()
{
	if (checkArgs())
	{
		_setter->appendTWB(CLT_MODEIA),
		PRINT_ERR(ERROR_MODEIA);
		return;
	}
	bool sign = _spltcmd[2][0] == '+';
	Channel *cha = _sInfs->getChannelByName(_spltcmd[1]);
	for (size_t i = 1; i < _spltcmd[2].size(); i++)
	{
		switch (_spltcmd[2][i])
		{
			case 'i':
				cha->setNeedInvite(sign);
				_setter->appendTWB(CLT_MODE_I);
				PRINT_INFOS(MODE_I);
				break;
			case 't':
				cha->setProtectTopic(sign);
				_setter->appendTWB(CLT_MODE_T);
				PRINT_INFOS(MODE_T);
				break;
			case 'k':
				if (sign && _spltcmd.size() > 3)
					cha->setPass(_spltcmd[3]);
				else
					cha->setPass("");
				_setter->appendTWB(CLT_MODE_K);
				PRINT_INFOS(MODE_K);
				break;
			case 'o':
				if (!_spltcmd[3].empty())
				{
					User *targetU = _sInfs->searchUser(_spltcmd[3]);
					if (targetU && targetU != cha->getOwner())
					{
						if (sign)
							cha->addOp(_sInfs->searchUser(_spltcmd[3]));
						else
							cha->removeOp(_sInfs->searchUser(_spltcmd[3]));
					}
				}
				_setter->appendTWB(CLT_MODE_O);
				PRINT_INFOS(MODE_O);
				break;
			case 'l':
				cha->setLimitedUsers(sign);
				if (sign && _spltcmd.size() > 3)
					cha->setMaxUser(strtol(_spltcmd[3].c_str(), NULL, 10));
				_setter->appendTWB(CLT_MODE_L);
				PRINT_INFOS(MODE_L);
				break;
			case 'b':
				cha->setBotChannel(sign);
				_setter->appendTWB(CLT_MODE_B);
				PRINT_INFOS(MODE_B);
				break;
		}
	}
}
