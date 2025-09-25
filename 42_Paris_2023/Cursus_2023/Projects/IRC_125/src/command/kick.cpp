#include "irc.hpp"

bool Kick::checkArgsKick()
{
  if (!this->_sInfs->getChannelByName(this->_spltcmd[1]))
    return (_setter->appendTWB(CLT_KICKEC), PRINT_WARNING(WARNING_KICKEC), false);
  this->_chan = this->_sInfs->getChannelByName(this->_spltcmd[1]);
  if (this->_chan->isUserInChannel(this->_sInfs->searchUser(this->_spltcmd[2])) == false)
    return (_setter->appendTWB(CLT_KICKEU), PRINT_WARNING(WARNING_KICKEU), false);
  this->_target = this->_sInfs->searchUser(this->_spltcmd[2]);
  if (this->_chan->isOpChannel(this->_setter) == false)
    return (_setter->appendTWB(CLT_KICKRK), PRINT_WARNING(WARNING_KICKRK), false);
  if (this->_chan->getOwner() == this->_target)
    return (_setter->appendTWB(CLT_KICKNO), PRINT_WARNING(WARNING_KICKNO), false);
  return (true);
}

Kick::Kick(Server *sInfs, std::vector<std::string> spltCmd, User *sender) : ACommand(sInfs, spltCmd, sender)
{
  if (this->_spltcmd.size() < 4)
  {
    _setter->appendTWB(CLT_KICKEA);
    PRINT_WARNING(WARNING_KICKEA);
    return;
  }
  else if (this->checkArgsKick() == false)
  {
    _setter->appendTWB(CLT_KICKIA);
    PRINT_ERR(ERROR_KICKIA);
    return;
  }
  else
    this->executeCmd();
}

void Kick::executeCmd()
{
  std::string reason = ":" + _target->getPrefix() + " PART " + _chan->getName();
  if (_spltcmd.size() > 3 && !_spltcmd[3].empty())
  {
      reason += " :" + _spltcmd[3];
  }
  reason += "\r\n";

  _chan->sendAll(reason);
  this->_chan->removeUser(this->_target);
  PRINT_INFOS(KICK_DATA);
}
