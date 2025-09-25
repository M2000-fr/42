/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invite.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:14:09 by jealefev          #+#    #+#             */
/*   Updated: 2025/07/31 14:31:18 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef INVITE_HPP
# define INVITE_HPP

# include "../irc.hpp"

class Invite : public ACommand
{
    private:
        User *_target;
        Channel *_channel;

    public:
        Invite(Server *sInfs, std::vector<std::string> spltCmd, User *setter);
        void executeCmd();
        bool checkArgsInvite();
};

#endif