/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:14:06 by jealefev          #+#    #+#             */
/*   Updated: 2025/07/31 14:31:18 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef JOIN_HPP
# define JOIN_HPP

# include "../irc.hpp"

class Join : public ACommand
{
 	public:
		Join(Server *sInfs, std::vector<std::string> spltCmd, User *sender) : ACommand(sInfs, spltCmd, sender) {std::cout << "join called" << std::endl; executeCmd();}
		void executeCmd(void);
		int checkArgs(void) const;   
};

#endif