/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:13:46 by jealefev          #+#    #+#             */
/*   Updated: 2025/07/31 14:31:18 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PASS_HPP
# define PASS_HPP

# include "../irc.hpp"

class Pass : public ACommand
{
    public:
        Pass(Server *sInfs, std::vector<std::string> spltCmd, User *sender) : ACommand(sInfs, spltCmd, sender) {executeCmd();}
        void executeCmd();
        int checkArgs(void) const;
};

#endif