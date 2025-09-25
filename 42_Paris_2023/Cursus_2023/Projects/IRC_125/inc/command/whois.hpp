/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whois.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:18:23 by abutet            #+#    #+#             */
/*   Updated: 2025/08/04 14:44:22 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef WHOIS_HPP
# define WHOIS_HPP

# include "irc.hpp"

class Whois : public ACommand
{
 	public:
		Whois(Server *sInfs, std::vector<std::string> spltCmd, User *sender) : ACommand(sInfs, spltCmd, sender) {std::cout << "Whois called" << std::endl; executeCmd();}
		void executeCmd(void);
		bool checkArgs(void);
};

#endif
