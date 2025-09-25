/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:20:24 by jealefev          #+#    #+#             */
/*   Updated: 2025/07/31 14:31:18 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef QUIT_HPP
# define QUIT_HPP

class Quit: public ACommand
{
    public:
        Quit(Server *sInfs, std::vector<std::string> spltCmd, User *sender) : ACommand(sInfs, spltCmd, sender) {executeCmd();}
        void executeCmd();
        bool checkArgs();
};

#endif
