/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:22:06 by jealefev          #+#    #+#             */
/*   Updated: 2025/07/31 14:31:18 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PART_HPP
# define PART_HPP
# include "irc.hpp"

class Part : public ACommand
{
    private:
        Channel *_target;

    public:
        Part(Server *sInfs, std::vector<std::string> spltCmd, User *sender);
        void executeCmd();
        bool checkArgs();
};

#endif