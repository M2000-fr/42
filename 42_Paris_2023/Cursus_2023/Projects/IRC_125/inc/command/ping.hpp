/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:18:23 by abutet            #+#    #+#             */
/*   Updated: 2025/08/04 14:28:50 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef PING_HPP
# define PING_HPP

# include "irc.hpp"

class Ping : public ACommand
{
 	public:
		Ping(Server *sInfs, std::vector<std::string> spltCmd, User *sender) : ACommand(sInfs, spltCmd, sender) {std::cout << "ping called" << std::endl; executeCmd();}
		void executeCmd(void);
		bool checkArgs(void);
};

#endif
