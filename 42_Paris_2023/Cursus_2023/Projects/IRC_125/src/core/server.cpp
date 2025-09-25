/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/08/18 14:35:55 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.hpp"

volatile sig_atomic_t g_stop = 0;

void handler(int sig)
{
	(void)sig;
	g_stop = 1;
}

Server::Server(int port, const std::string &password) : _port(port), _password(password)
{
	PRINT_METHOD(SERVER_CONST);
}

Server::~Server()
{
	PRINT_METHOD(SERVER_DESTR);
}

std::string Server::getPassword() const
{
	return (this->_password);
}

long Server::getPort() const
{
	return (this->_port);
}

void Server::addChannel(Channel *channel)
{
	this->_channels.push_back(channel);
}

std::list<Channel *> &Server::getChannels()
{
	return this->_channels;
}

Channel *Server::getChannelByName(const std::string &name) const
{
	PRINT_METHOD(CHA_SEARCHCHA);
	for (std::list<Channel *>::const_iterator it = _channels.begin(); it != _channels.end(); ++it)
	{
		PRINT_METHOD(CHA_COMPARCHA);
		if ((*it)->getName() == name)
			return *it;
	}
	return NULL;
}

std::vector<std::string> split(const std::string s)
{
	std::vector<std::string> tokens;
	std::istringstream ss(s);
	std::string token;
	bool ar = false;

	while (std::getline(ss, token, ' '))
	{
		if (ar)
		{
			tokens.back() += " " + token;
			continue;
		}
		if (token[0] == ':')
		{
			ar = true;
			token.erase(0, 1);
		}
		tokens.push_back(token);
	}
	return tokens;
}

void Server::printChannels() const
{
	if (_channels.empty())
	{
		std::cout << "No channels on the server." << std::endl;
		return;
	}

	std::cout << "List of channels:" << std::endl;
	for (std::list<Channel *>::const_iterator it = _channels.begin(); it != _channels.end(); ++it)
	{
		Channel *channel = *it;
		if (channel)
		{
			channel->getChannelInfs();
		}
	}
}

void Server::makeCmd(std::string rawCmd, User *setter)
{
	std::string names[12] = {"PASS", "NICK", "USER", "JOIN", "PRIVMSG", "PART", "MODE", "KICK", "INVITE", "TOPIC", "PING", "WHOIS"};

	std::vector<std::string> spltCmd = split(rawCmd);
	if (spltCmd[0] == "QUIT" && spltCmd.size() < 2)
	{
		Quit(this, spltCmd, setter);
		return ;
	}
	if (spltCmd.size() < 2)
		return ;
	(void)setter;
	for (size_t i = 0; i < 12; ++i)
	{
		if (spltCmd[0] == names[i])
		{
			switch (i)
			{
			case 0:
				Pass(this, spltCmd, setter);
				break;
			case 1:
				Nick(this, spltCmd, setter);
				break;
			case 2:
				Name(this, spltCmd, setter);
				break;
			case 3:
				Join(this, spltCmd, setter);
				break;
			case 4:
				PrivMsg(this, spltCmd, setter);
				break;
			case 5:
				Part(this, spltCmd, setter);
				break;
			case 6:
				Mode(this, spltCmd, setter);
				break;
			case 7:
				Kick(this, spltCmd, setter);
				break;
			case 8:
				Invite(this, spltCmd, setter);
				break;
			case 9:
				Topic(this, spltCmd, setter);
				break;
			case 10:
				Ping(this, spltCmd, setter);
				break;
			case 11:
				Whois(this, spltCmd, setter);
				break;
			}
			return ;
		}
	}
	return ;
}

bool readCommandIfAny(std::string &out)
{
	fd_set fd;
	FD_ZERO(&fd);
	FD_SET(STDIN_FILENO, &fd);

	timeval(tv);
	tv.tv_sec = 0;
	tv.tv_usec = 0;

	int r = select(STDIN_FILENO + 1, &fd, NULL, NULL, &tv);
	if (r > 0 && FD_ISSET(STDIN_FILENO, &fd))
	{
		std::string tmp;
		if (std::getline(std::cin, tmp))
		{
			for (size_t i = 0; i < tmp.size(); i++)
				tmp[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(tmp[i])));
			out = tmp;
			return (true);
		}
		else
			std::cin.clear();
	}
	return (false);
}

void Server::disconnectClient(int fd)
{
	User *user = _users[fd];
	std::list<Channel *> delet;
	for (std::list<Channel *>::iterator it = _channels.begin(); it != _channels.end(); ++it)
	{
		(*it)->removeUser(user);
		if ((*it)->getUsers().empty())
		{
			delet.push_back((*it));
		}
	}
	for (std::list<Channel *>::iterator it = delet.begin(); it != delet.end(); ++it)
	{
		delete this->getChannelByName((*it)->getName());
		_channels.remove((*it));
	}
	_pollManager.removeClient(fd);
	delete user;
	_users.erase(fd);
}

User *Server::searchUser(std::string target)
{
	for (std::map<int, User *>::const_iterator it = _users.begin(); it != _users.end(); ++it)
	{
		if (!target.compare(it->second->getNick()))
			return (it->second);
	}
	return (NULL);
}

int Server::start()
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handler);
	if ((_serverFd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	return (PRINT_ERR(ERROR_SOCKET), 0);
	sockaddr_in addr;
	std::string str;
	std::memset(&addr, 0, sizeof(addr));
	addr.sin_port = htons(_port);
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_family = AF_INET;
	if (bind(_serverFd, (sockaddr *)&addr, sizeof(addr)) == -1)
		return (PRINT_ERR(ERROR_BIND), 0);
	else if (listen(_serverFd, 10) == -1)
		return (PRINT_ERR(ERROR_LISTEN), 0);
	PRINT_SUCCESS(SUCCESS_START);
	PRINT_DEBUG(BEGIN_SERVER);
	_pollManager.setServerFd(_serverFd);
	std::vector<int> newClients;
	std::vector<int> disconnected;
	std::vector<std::pair<int, std::string> > readyClients;
	std::vector<int> readyToWrite;
	printUsr();
	printChannels();

	while (!g_stop && str != "close")
	{
		readCommandIfAny(str);
		newClients.clear();
		disconnected.clear();
		readyClients.clear();
		readyToWrite.clear();

		if (str == "flag" && g_flag == 0)
		{
			g_flag = 1;
			str.clear();
			std::cout << BOLD UNDERLINE GREEN << "\nFlag have been set to 1 !\n" << RESET << std::endl;
		}
		else if (str == "flag" && g_flag == 1)
		{
			g_flag = 0;
			str.clear();
			std::cout << BOLD UNDERLINE GREEN << "\nFlag have been set to 0 !\n" << RESET << std::endl;
		}
		else if (str == "close")
			std::cout << BOLD UNDERLINE GREEN << "\nServer is going to close !\n" << RESET << std::endl;
		_pollManager.pollLoop(_serverFd, newClients, disconnected, readyClients, readyToWrite);
		for (size_t i = 0; i < newClients.size(); i++)
		{
			_users[newClients[i]] = new User(newClients[i], _pollManager);
			printUsr();
			printChannels();
		}

		for (size_t i = 0; i < disconnected.size(); i++)
		{
			disconnectClient(disconnected[i]);
			printUsr();
			printChannels();
		}

		for (size_t i = 0; i < readyClients.size(); i++)
		{
			int fd = readyClients[i].first;
			const std::string &data = readyClients[i].second;

			if (_users.count(fd))
			{
				_users[fd]->appendTRB(data);
				std::string rawCmd;
				while (_users.count(fd) && !(rawCmd = _users[fd]->extractCmd()).empty())
				{
					makeCmd(rawCmd, _users[fd]);
				}
				printUsr();
				printChannels();
			}
		}
		for (size_t i = 0; i < readyToWrite.size(); i++)
		{
			int fd = readyToWrite[i];
			if (_users.count(fd))
			{
				std::string writeBuffer = _users[fd]->getWriteBuffer();
				if (!writeBuffer.empty())
				{
					ssize_t bytesSent = send(fd, writeBuffer.c_str(), writeBuffer.size(), MSG_NOSIGNAL);
					if (bytesSent < 0)
					{
						std::cerr << "Erreur send sur fd " << fd << std::endl;
						disconnectClient(fd);
					}
					else
					{
						_users[fd]->clearWriteBuffer();
						_pollManager.setWritable(fd, false);
					}
				}
			}
		}
	}
	disconnected.clear();
	for (std::map<int, User *>::const_iterator it = _users.begin(); it != _users.end(); ++it)
	{
		disconnected.push_back((*it).second->getFd());
	}
	for (size_t i = 0; i < disconnected.size(); i++)
	{
		disconnectClient(disconnected[i]);
	}
	PRINT_DEBUG(END_SERVER);
	return (1);
}

void Server::printUsr() const
{
	std::cout << "Connected users -> " << _users.size() << std::endl;
	for (std::map<int, User *>::const_iterator it = _users.begin(); it != _users.end(); ++it)
	{
		PRINT_INFOS("User fd: " << it->second->getFd());
		PRINT_INFOS("Name: " << it->second->getUser());
		PRINT_INFOS("Real name: " << it->second->getReal());
		PRINT_INFOS("Nickname: " << it->second->getNick());
		PRINT_INFOS("Host: " << it->second->getHost());
		PRINT_INFOS("IP: " << it->second->getIp());
		PRINT_INFOS("Prefix: " << it->second->getPrefix());
		PRINT_INFOS("has passwd: " << it->second->getHasPass());
	}
}
