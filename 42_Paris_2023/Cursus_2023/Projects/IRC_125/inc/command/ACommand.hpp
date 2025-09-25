/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  ACommand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:05:49 by mechard           #+#    #+#             */
/*   Updated: 2025/07/16 13:05:49 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ACommand_HPP
# define ACommand_HPP

# include "../irc.hpp"

class ACommand
{
    protected:
        Server *_sInfs;
        std::vector<std::string> _spltcmd;
        User *_setter;

    public:
        ACommand(Server *sInfs, const std::vector<std::string> spltcmd, User *sender);
        virtual ~ACommand();
        std::string getSender() const;
        std::vector<std::string> getSpltCmd();
        void printSpltcmd();
        virtual void executeCmd() = 0;
};

#endif