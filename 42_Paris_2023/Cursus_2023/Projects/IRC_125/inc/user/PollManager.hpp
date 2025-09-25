/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PollManager.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:23:40 by mechard           #+#    #+#             */
/*   Updated: 2025/07/17 15:23:40 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef POLLMANAGER_HPP
# define POLLMANAGER_HPP

class PollManager
{
	private:
		std::vector<struct pollfd> _fds;

	public:
		PollManager();
		~PollManager();

		void setServerFd(int fd);
		void addClient(int fd);
		void addStdin();
		void removeClient(int fd);
		void setWritable(int fd, bool enable);
		int pollLoop(int server_fd, std::vector<int> &newClients, std::vector<int> &disconnect, std::vector<std::pair<int, std::string> > &readyClients, std::vector<int> &readyToWrite);
};

#endif