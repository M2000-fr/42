/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:06:08 by mechard           #+#    #+#             */
/*   Updated: 2025/07/16 13:06:08 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "irc.hpp"

Channel::Channel(const std::string &_name, User *_owner, size_t maxUsers, bool needInvite, bool limitedUsers)
{
	this->_name = _name;
	this->_owner = _owner;
	this->_limitedUsers = limitedUsers;
	this->_maxUsers = maxUsers;
	this->_needInvite = needInvite;
	this->_protectTopic = false;
	this->_botChannel = false;
	this->_topic = "";
	this->_bot = Bot(this);
	std::cout << "channel created :" << this->_name << std::endl;
    PRINT_METHOD(CHANNEL_CONSTRUCT);
}

Channel::~Channel()
{
	_users.clear();
	_ops.clear();
	_invited.clear();
    PRINT_METHOD(CHANNEL_DESTRUCTO);
}

bool Channel::getAlreadyRegistered(User *setter) const
{
	return std::find(_users.begin(), _users.end(), setter) != _users.end();
}

void Channel::getChannelInfs()
{
	std::cout << "====================== CHANNEL INFOS ======================" << std::endl;
	std::cout << "_name            : " << this->getName() << std::endl;
	std::cout << "Topic           : " << this->getTopic() << std::endl;
	std::cout << "_password        : " << (this->getPass().empty() ? "(none)" : this->getPass()) << std::endl;
	std::cout << "_owner           : " << (this->getOwner() ? this->getOwner()->getNick() : "NULL") << std::endl;
	std::cout << "Max Users       : " << this->getMaxUsers() << std::endl;
	std::cout << "User Count      : " << this->getUsersNumber() << std::endl;
	std::cout << "Invite Only     : " << (this->getNeedInvite() ? "Yes" : "No") << std::endl;
	std::cout << "Topic Protected : " << (this->getProtectTopic() ? "Yes" : "No") << std::endl;
	std::cout << "Bot Channel     : " << (this->getBotChannel() ? "Yes" : "No") << std::endl;

	std::cout << "Operators       : ";
	if (_ops.empty())
		std::cout << "(none)";
	else
	{
		for (std::list<User *>::iterator it = _ops.begin(); it != _ops.end(); ++it)
			std::cout << (*it)->getNick() << " ";
	}
	std::cout << std::endl;

	std::cout << "Users           : ";
	if (_users.empty())
		std::cout << "(none)";
	else
	{
		for (std::list<User *>::iterator it = _users.begin(); it != _users.end(); ++it)
			std::cout << (*it)->getNick() << " ";
	}
	std::cout << std::endl;

	std::cout << "Invited Users   : ";
	if (_invited.empty())
		std::cout << "(none)";
	else
	{
		for (std::list<User *>::const_iterator it = _invited.begin(); it != _invited.end(); ++it)
			std::cout << (*it)->getNick() << " ";
	}
	std::cout << std::endl;

	std::cout << "==========================================================" << std::endl;
}

std::string Channel::getName() const
{
	return (this->_name);
}

std::string Channel::getTopic() const
{
	return (this->_topic);
}

User *Channel::getOwner() const
{
	return (this->_owner);
}

std::list<User *> &Channel::getUsers()
{
	return (this->_users);
}

size_t Channel::getUsersNumber()
{
	return (this->_users.size());
}

std::list<User *> &Channel::getOps()
{
	return (this->_ops);
}

std::string Channel::getPass() const
{
	return (this->_pass);
}

size_t Channel::getMaxUsers() const
{
	return (this->_maxUsers);
}

bool Channel::getLimitedUsers() const
{
	return (this->_limitedUsers);
}

bool Channel::getNeedInvite() const
{
	return (this->_needInvite);
}

void Channel::setNeedInvite(bool toSet)
{
	this->_needInvite = toSet;
}

void Channel::setMaxUser(size_t arg)
{
	this->_maxUsers = arg;
}

void Channel::setLimitedUsers(bool arg)
{
	this->_limitedUsers = arg;
}

std::list<User *> Channel::getInvited() const
{
	return (this->_invited);
}

bool Channel::isOp(User *user) const
{
	for (std::list<User *>::const_iterator it = this->_ops.begin(); it != this->_ops.end(); ++it)
	{
		if (*it == user)
		{
			return (true);
		}
	}
	return (false);
}

bool Channel::isUserInChannel(User *user) const
{
	for (std::list<User *>::const_iterator it = this->_users.begin(); it != this->_users.end(); ++it)
	{
		if (*it == user)
		{
			return (true);
		}
	}
	return (false);
}

bool Channel::isOpChannel(User *user) const
{
	for (std::list<User *>::const_iterator it = this->_ops.begin(); it != this->_ops.end(); ++it)
	{
		if (*it == user)
		{
			return (true);
		}
	}
	return (false);
}

bool Channel::getProtectTopic() const
{
	return (this->_protectTopic);
}

Channel Channel::getChannel() const
{
	return *this;
}

void Channel::setProtectTopic(bool toSet)
{
	this->_protectTopic = toSet;
}

void Channel::setTopic(const std::string &topic)
{
	this->_topic = topic;
}

void Channel::setPass(const std::string &new_pass)
{
	if (!new_pass.empty())
		this->_pass = new_pass;
	else
		this->_pass = "";
}

void Channel::addOp(User *user)
{
	if (this->isOp(user) == false)
		this->_ops.push_back(user);
	else
		std::cerr << user->getUser() << " is already an operator in the channel " << this->_name << std::endl;
}

void Channel::addOwner(User *user)
{
	if (this->_owner == NULL)
		this->_owner = user;
	else
		std::cerr << user->getUser() << " is already the _owner of this channel " << this->_name << std::endl;
}

void Channel::addUser(User *user)
{
	if (!user)
	{
		std::cerr << "Error: Attempt to add a null user to the channel " << this->_name << std::endl;
		PRINT_DEBUG("Attempt to add a null user to the channel " << this->_name);
		return;
	}
	if (this->isUserInChannel(user) == false)
	{
		PRINT_DEBUG(GREEN "Adding user " << user->getUser() << " to channel " << this->_name << WHITE);
		this->_users.push_back(user);
	}
	else
	{
		PRINT_DEBUG("User " << user->getUser() << " is already in channel " << this->_name);
		std::cerr << user->getUser() << " is already in the channel " << this->_name << std::endl;
	}
}

void Channel::removeUser(User *user)
{
	if (this->isUserInChannel(user) == true)
	{
		removeOp(user);
		if (getOwner() == user)
			_owner = NULL;
		this->_users.remove(user);
	}
	else
		std::cerr << user->getUser() << " is not in the channel " << this->_name << std::endl;
}

void Channel::removeOp(User *user)
{
	if (this->isOp(user) == true)
		this->_ops.remove(user);
	else
		std::cerr << user->getUser() << " is not an operator in the channel " << this->_name << std::endl;
}

void Channel::sendAll(const std::string &toSend, User *exclude)
{
	for (std::list<User *>::iterator it = _users.begin(); it != _users.end(); ++it)
	{
		if (*it != exclude)
		{
			std::cout << "envoye à " << (*it)->getNick() << std::endl;
			(*it)->appendTWB(toSend);
		}
	}
}

void Channel::addInvited(User *user)
{
	if (user && !isInvited(user))
		_invited.push_back(user);
}

bool Channel::isInvited(User *user) const
{
	if (user)
	{
		if (std::find(_invited.begin(), _invited.end(), user) != _invited.end())
			return (true);
	}
	std::cerr << user->getUser() << " is not invited to the channel " << this->_name << std::endl;
	return (false);
}

void Channel::setBotChannel(bool isBot)
{
	_botChannel = isBot;
}

bool Channel::getBotChannel() const
{
	return (_botChannel);
}

void Channel::botCmd(const std::string cmd, User *setter)
{
	_bot.cmd(cmd, setter);
}
