/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:06:23 by mechard           #+#    #+#             */
/*   Updated: 2025/07/16 13:06:23 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "irc.hpp"

User::User(int fd, PollManager &poll) : _fd(fd), _regis(false), _hasNick(false), _hasUser(false),
										_hasPass(false), _poll(poll)
{
	PRINT_METHOD(USER_CONSTRU);
}

User::~User()
{
	PRINT_METHOD(USER_DESTRUC);
}

int User::getFd() const
{
	return (this->_fd);
}

const std::string User::getNick() const
{
	return (this->_nick);
}

void User::setUser(const std::string &user)
{
	_usr = user;
	_hasUser = true;
}

void User::setNick(const std::string &nick)
{
	if (nick.empty())
		PRINT_ERR(ERROR_EMPTYN);
	else if (nick == "anonymous")
		PRINT_ERR(ERROR_ANONYM);
	else if (nick.length() > 9)
		PRINT_ERR(ERROR_NTLONG);
	else if (this->_nick == nick)
		PRINT_ERR(ERROR_SNICKN);
	else
	{
		this->_nick = nick;
		_hasNick = true;
	}
}

void User::setRegis()
{
	_regis = true;
}

bool User::isRegis() const
{
	return (_regis);
}

void User::appendTRB(const std::string &data)
{
	_readBuf += data;
}

void User::appendTWB(const std::string &data)
{
	_writeBuf += data;
	_poll.setWritable(_fd, true);
}

void User::registration()
{
	if (_regis)
		return;
	if (_hasNick && _hasUser && _hasPass)
	{
		PRINT_INFOS("_registered");
		_regis = true;
		resolveHost();
		appendTWB((std::string) ":localhost 001 " + _nick + SUCCESS_CONNE);
		appendTWB(":localhost 001 " + _nick + " :Welcome to the IRC server " + getPrefix() + "\r\n");
	}
	else if (_hasNick && _hasUser && !_hasPass)
		appendTWB((std::string) ":localhost 451 * :You must send PASS to _register\r\n");
}

bool User::isReadyToSend() const
{
	return (!_writeBuf.empty());
}

std::string User::extractCmd()
{
	size_t pos = _readBuf.find("\r\n");

	if (pos != std::string::npos)
	{
		std::string command = _readBuf.substr(0, pos);
		_readBuf.erase(0, pos + 2);
		return (command);
	}

	pos = _readBuf.find('\n');
	if (pos != std::string::npos)
	{
		std::string command = _readBuf.substr(0, pos);
		_readBuf.erase(0, pos + 1);
		return (command);
	}
	return ("");
}

void User::setHasNick(bool value)
{
	_hasNick = value;
}

void User::setHasUser(bool value)
{
	_hasUser = value;
}

void User::setHasPass(bool value)
{
	_hasPass = value;
}

bool User::getHasPass() const
{
	return (_hasPass);
}

bool User::hasDataToSend() const
{
	return (!_writeBuf.empty());
}

const std::string User::getWriteBuffer() const
{
	return (_writeBuf);
}

void User::clearWriteBuffer()
{
	_writeBuf.clear();
}

const std::string User::getPrefix() const
{
	return (_nick + "!" + _usr + "@" + _host);
}

const std::string User::getUser() const
{
	return (_usr);
}

const std::string User::getHost() const
{
	return (_host);
}

const std::string User::getIp() const
{
	return (_ip);
}

const std::string User::getReadBuffer() const
{
	return (_readBuf);
}

void User::setHost(const std::string &host)
{
	this->_host = host;
}

void User::setIp(const std::string &ip)
{
	this->_ip = ip;
}

void User::resolveHost()
{
	struct sockaddr_in addr;
	socklen_t len = sizeof(addr);

	if (getpeername(_fd, (struct sockaddr *)&addr, &len) == -1)
	{
		std::cerr << "getpeername failed for _fd " << _fd << std::endl;
		return;
	}

	_ip = std::string(inet_ntoa(addr.sin_addr));

	struct hostent *host = gethostbyaddr((const void *)&addr.sin_addr, sizeof(addr.sin_addr), AF_INET);
	if (host)
		this->_host = std::string(host->h_name);
	else
		this->_host = this->_ip;
}

void User::setReal(const std::string &real)
{
	this->_real = real;
}

const std::string User::getReal(void) const
{
	return (_real);
}

void User::consumeWriteBuffer(size_t len)
{
	if (len >= _writeBuf.size())
		_writeBuf.clear();
	else
		_writeBuf.erase(0, len);
}
