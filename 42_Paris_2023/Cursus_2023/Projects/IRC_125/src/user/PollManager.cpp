/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PollManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:25:38 by mechard           #+#    #+#             */
/*   Updated: 2025/07/17 15:25:38 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.hpp"

PollManager::PollManager()
{
	PRINT_METHOD(PM_CONSTRUCT);
}

PollManager::~PollManager()
{
	for (size_t i = 0; i < _fds.size(); i++)
		close(_fds[i].fd);
	PRINT_METHOD(PM_DESTRUCTO);
}

void PollManager::addClient(int fd)
{
	struct pollfd pfd;
	std::memset(&pfd, 0, sizeof(pfd));
	pfd.fd = fd;
	pfd.events = POLLIN;
	_fds.push_back(pfd);
	PRINT_INFOS(CLIENT_CONNE);
}

void PollManager::removeClient(int fd)
{
	for (size_t i = 0; i < _fds.size(); i++)
	{
		if (_fds[i].fd == fd)
		{
			_fds.erase(_fds.begin() + i);
			break;
		}
	}
	close(fd);
	PRINT_INFOS(CLIENT_DISCO);
}

void PollManager::setServerFd(int fd)
{
	struct pollfd pfd;
	pfd.fd = fd;
	pfd.events = POLLIN;
	_fds.push_back(pfd);
}

void PollManager::setWritable(int fd, bool enable)
{
	for (size_t i = 0; i < _fds.size(); i++)
	{
		if (_fds[i].fd == fd)
		{
			if (enable)
				_fds[i].events |= POLLOUT;
			else
				_fds[i].events &= ~POLLOUT;
		}
	}
}

int PollManager::pollLoop(int server_fd, std::vector<int> &newClients, std::vector<int> &disconnected, std::vector<std::pair<int, std::string> > &readyClients, std::vector<int> &readyToWrite)
{
	int ms = 10;
	if (_fds.empty()) {
        poll(NULL, 0, ms);
        return 0;
    }

	int poll_error = poll(&_fds[0], _fds.size(), ms);
	if (poll_error == -1)
		return (PRINT_ERR(ERROR_POLLTO), 1);
	for (size_t i = 0; i < _fds.size(); ++i)
	{
		int fd = _fds[i].fd;
		if ((fd == server_fd) && (_fds[i].revents & POLLIN))
		{
			int client_fd = accept(server_fd, NULL, NULL);
			if (client_fd == -1)
			{
				PRINT_ERR(ERROR_POLLAC);
				continue;
			}
			addClient(client_fd);
			newClients.push_back(client_fd);
		}
		else if (_fds[i].revents & POLLIN)
		{
			char buff[1024];
			long long bytes = recv(fd, buff, sizeof(buff) - 1, 0);
			if (bytes > 0)
			{
				buff[bytes] = '\0';
				readyClients.push_back(std::make_pair(fd, std::string(buff)));
				PRINT_METHOD(PM_DATA);
			}
			else
			{
				removeClient(fd);
				disconnected.push_back(fd);
				i--;
			}
		}
		else if (_fds[i].revents & POLLOUT)
			readyToWrite.push_back(fd);
	}
	return (0);
}
