/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:05:59 by mechard           #+#    #+#             */
/*   Updated: 2025/07/16 13:05:59 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef USER_HPP
# define USER_HPP

class User
{
	private:
		int _fd;

		std::string _nick;
		std::string _host;
		std::string _readBuf;
		std::string _writeBuf;
		std::string _usr;
		std::string _real;
		std::string _ip;

		bool _regis;
		bool _hasNick;
		bool _hasUser;
		bool _hasPass;

		PollManager &_poll;

	public:
		User(int fd, PollManager &poll);
		~User();
		int getFd() const;
		void appendTRB(const std::string &data);
		void appendTWB(const std::string &data);
		std::string extractCmd();
		void registration();
		void resolveHost();

		void setRegis();
		void setNick(const std::string &nick);
		void setUser(const std::string &user);
		void setReal(const std::string &real);
		void setHasNick(bool value);
		void setHasUser(bool value);
		void setHasPass(bool value);
		void setHost(const std::string &host);
		void setIp(const std::string &ip);
		const std::string getUser(void) const;
		const std::string getReal(void) const;
		const std::string getNick() const;
		const std::string getWriteBuffer() const;
		const std::string getHost() const;
		const std::string getIp() const;
		const std::string getPrefix() const;
		const std::string getReadBuffer() const;

		bool hasDataToSend() const;
		bool getHasPass() const;
		bool isReadyToSend() const;
		bool isRegis() const;

		void clearWriteBuffer();
		void consumeWriteBuffer(size_t len);
};
#endif
