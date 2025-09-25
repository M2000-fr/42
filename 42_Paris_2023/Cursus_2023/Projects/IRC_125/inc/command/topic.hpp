/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topic.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealefev <jealefev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:14:19 by jealefev          #+#    #+#             */
/*   Updated: 2025/07/31 14:31:18 by jealefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef TOPIC_HPP
# define TOPIC_HPP

# include "../irc.hpp"

class Topic : public ACommand
{
    private:
        Channel *_channel;

    public:
        Topic(Server *sInfs, std::vector<std::string> spltCmd, User *sender);
        void executeCmd();
        bool checkArgs();
};

#endif