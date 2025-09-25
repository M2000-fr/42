/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:23:06 by abutet            #+#    #+#             */
/*   Updated: 2025/08/14 14:40:11 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SERVER_HPP
# define SERVER_HPP

class User;
class Channel;
class ACommand;

class Server
{
	private:
		long _port;
		int _serverFd;
		std::string _password;
		PollManager _pollManager;
		std::map<int, User *> _users;
		std::list<Channel *> _channels;

	public:
		Server(int port, const std::string &password);
		~Server();
		int start();
		long getPort() const;
		std::string getPassword() const;
		Channel *getChannelByName(const std::string &name) const;

		void disconnectClient(int fd);
		void makeCmd(std::string rawCmd, User *setter);
		void printUsr() const;
		void addChannel(Channel *Channel);
		std::list<Channel *> &getChannels();
		User *searchUser(std::string target);
		void printChannels() const;
};

#endif
