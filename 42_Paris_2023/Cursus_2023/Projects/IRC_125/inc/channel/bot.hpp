/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 09:41:27 by abutet            #+#    #+#             */
/*   Updated: 2025/08/18 13:29:47 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "irc.hpp"

class Bot
{
	private:
		Channel *_channel;
		std::vector<std::pair<std::string, std::string> > _cmd;
	public:
		Bot();
		Bot(Channel *cha);
		~Bot();
		std::vector<std::pair<std::string, std::string> > &getcmd();
		std::vector<std::pair<std::string, std::string> >::iterator cmdIterator(std::string name);
		bool addCmd(const std::string name, const std::string cmd);
		bool rmCmd(const std::string name);
		void cmd(const std::string cmd, User *setter);
};

