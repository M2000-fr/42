/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:05:43 by mechard           #+#    #+#             */
/*   Updated: 2025/07/16 13:05:43 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "irc.hpp"

class Channel
{
	private:
		std::string _name;
		User *_owner;
		std::string _pass;
		size_t _maxUsers;
		bool _needInvite;
		bool _protectTopic;
		bool _limitedUsers;
		std::string _topic;
		std::list<User *> _ops;
		std::list<User *> _users;
		std::list<User *> _invited;
		bool _botChannel;
		Bot _bot;

	public:
		Channel(const std::string &name, User *owner, size_t maxUsers, bool needInvite, bool limitedUsers);
		~Channel();
		void sendAll(const std::string &toSend, User *exclude = NULL);
		std::string getName() const;
		std::string getTopic() const;
		size_t getMaxUsers() const;
		bool getLimitedUsers() const;
		User *getOwner() const;
		std::list<User *> &getOps();
		std::list<User *> &getUsers();
		std::list<Channel> &getChannel();
		std::list<User *> getInvited() const;
		std::string getPass() const;
		size_t getUsersNumber();
		bool isOp(User *user) const;
		bool isUserInChannel(User *user) const;
		bool isOpChannel(User *user) const;
		bool getNeedInvite() const;
		bool getProtectTopic() const;
		void setProtectTopic(bool toSet);
		void setLimitedUsers(bool args);
		void setMaxUser(size_t args);
		void setNeedInvite(bool toSet);
		void setTopic(const std::string &topic);
		void setPass(const std::string &newPass);
		void addOp(User *user);
		void addOwner(User *user);
		void addUser(User *user);
		void addInvited(User *user);
		bool isInvited(User *user) const;
		void removeUser(User *user);
		void removeOp(User *user);
		void setBotChannel(bool isBot);
		bool getBotChannel() const;
		Channel getChannel() const;
		void getChannelInfs();
		bool getAlreadyRegistered(User *setter) const;
		void botCmd(const std::string cmd, User *setter);
};
