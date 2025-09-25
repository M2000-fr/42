/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:14:01 by jealefev          #+#    #+#             */
/*   Updated: 2025/07/31 14:31:06 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MODE_HPP
# define MODE_HPP

# include "irc.hpp"

class Mode : public ACommand
{
	public:
		Mode(Server *sInfs, std::vector<std::string> spltCmd, User *sender) : ACommand(sInfs, spltCmd, sender) {executeCmd();}
		void executeCmd();
		int checkArgs(void) const;
};

#endif
