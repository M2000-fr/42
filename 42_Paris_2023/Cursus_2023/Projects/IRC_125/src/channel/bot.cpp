/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 09:53:43 by abutet            #+#    #+#             */
/*   Updated: 2025/08/18 13:29:41 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "irc.hpp"

Bot::Bot()
{
	_channel = NULL;
	addCmd("!help", "voici la list des commandes :");
	addCmd("!set", "error :");
	addCmd("!rm", "error :");
	addCmd("!welcome", "bienvenue sur le serveur!");
	PRINT_METHOD(BOT_CONSTRUCT);
}

Bot::Bot(Channel *cha) : _channel(cha)
{
	addCmd("!help", "voici la list des commandes :");
	addCmd("!set", "error :");
	addCmd("!rm", "error :");
	addCmd("!welcome", "bienvenue sur le serveur!");
	PRINT_METHOD(BOT_CONSTRUCT);
}

Bot::~Bot()
{
    PRINT_METHOD(BOT_DESTRUCTO);
}

std::vector<std::pair<std::string, std::string> > &Bot::getcmd()
{
	return (_cmd);
}

std::vector<std::pair<std::string, std::string> >::iterator Bot::cmdIterator(std::string name)
{
	for (std::vector<std::pair<std::string, std::string> >::iterator it = _cmd.begin();it != _cmd.end(); ++it)
	{
		if ((*it).first == name)
		{
			return (it);
		}
	}
	return (_cmd.end());
}

bool Bot::addCmd(const std::string name, const std::string cmd)
{
	if (name[0] != '!')
	{
		PRINT_ERR(ERROR_BOTPRE);
		return (false);
	}
	if (cmdIterator(name) != _cmd.end())
	{
		PRINT_WARNING(WARNING_BOTAUS);
		return (false);
	}
	_cmd.push_back(std::make_pair(name, cmd));
	if (_cmd.front().second.at(_cmd.front().second.size() - 1) == ':')
		_cmd.front().second.append(" " + name);
	else
		_cmd.front().second.append("\\" + name);
	return (true);
}

bool Bot::rmCmd(const std::string name)
{
	if (!name.compare("!help") || !name.compare("!set") || !name.compare("!rm"))
	{
		PRINT_WARNING(WARNING_BOTHPR);
		return (false);
	}
	std::vector<std::pair<std::string, std::string> >::iterator it = cmdIterator(name);
	if (it == _cmd.end())
	{
		PRINT_WARNING(WARNING_BOTCUK);
		return (false);
	}
	_cmd.erase(it);
	size_t pos = _cmd.front().second.find(name);
	if (pos < 0)
		return (PRINT_WARNING(WARNING_BOTERF), false);
	else if (pos + name.size() >= _cmd.front().second.size())
		_cmd.front().second.erase(pos - 1, name.size() + 1);
	else if (_cmd.front().second.at(pos + name.size()) == '\\')
		_cmd.front().second.erase(pos, name.size() + 1);
	else
		return (PRINT_WARNING(WARNING_BOTERF), false);
	return (true);
}

void Bot::cmd(const std::string cmd, User *setter)
{
	std::string name;
	std::string respond;

	for (size_t i = 0; i < cmd.size(); i++)
	{
		if (cmd[i] == ' ')
		{
			respond = cmd.substr(i + 1, cmd.size() - i - 1);
			break ;
		}
		name.push_back(cmd[i]);
	}
	if (!name.compare("!set"))
	{
		if (!_channel->isOp(setter))
			return (setter->appendTWB(CLT_BOTMOP), PRINT_WARNING(WARNING_BOTMOP));
		std::string name2;
		std::string respond2;

		for (size_t i = 0; i < respond.size(); i++)
		{
			if (respond[i] == ' ')
			{
				respond2 = respond.substr(i + 1, respond.size() - i - 1);
				break ;
			}
			name2.push_back(respond[i]);
		}
		if (!addCmd(name2, respond2))
			return (setter->appendTWB(CLT_BOTMOP), PRINT_WARNING(WARNING_BOTADD));
		return ;
	}
	if (!name.compare("!rm"))
	{
		if (!_channel->isOp(setter))
			return (setter->appendTWB(CLT_BOTADD), PRINT_WARNING(WARNING_BOTMOP));
		std::string name2;

		for (size_t i = 0; i < respond.size(); i++)
		{
			if (respond[i] == ' ')
				break ;
			name2.push_back(respond[i]);
		}
		if (!rmCmd(name2))
			return (setter->appendTWB(CLT_BOTRME), PRINT_WARNING(WARNING_BOTRME));
		return ;
	}
	std::vector<std::pair<std::string, std::string> >::iterator it = cmdIterator(name);
	if (it == _cmd.end())
		setter->appendTWB(":bot PRIVMSG " + _channel->getName() + " :unknown command\r\n");
	else
		setter->appendTWB(":bot PRIVMSG " + _channel->getName() + " :"  + (*it).second + "\r\n");
}
