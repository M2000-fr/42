/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:14:03 by jealefev          #+#    #+#             */
/*   Updated: 2025/08/13 11:42:30 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef KICK_HPP
# define KICK_HPP

# include "../irc.hpp"

class Kick : public ACommand
{
    private:
        Channel *_chan;
        User *_target;
    public:
        Kick(Server *sInfs, std::vector<std::string> spltCmd, User *sender);
        void executeCmd();
        bool checkArgsKick();

};

#endif
