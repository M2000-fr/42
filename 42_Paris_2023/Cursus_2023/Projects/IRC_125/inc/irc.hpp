/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   irc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:06:02 by mechard           #+#    #+#             */
/*   Updated: 2025/07/16 13:06:02 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef IRC_HPP
# define IRC_HPP

extern int g_flag;

/* EXTERNAL LYBRARY */

# include <sstream>
# include <sys/socket.h>
# include <netinet/in.h>
# include <signal.h>
# include <unistd.h>
# include <iostream>
# include <vector>
# include <list>
# include <map>
# include <string>
# include <cstring>
# include <cstdlib>
# include <cerrno>
# include <poll.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <algorithm>

/* PERSONNAL LIBRARY */

# include "PollManager.hpp"
# include "user.hpp"
# include "server.hpp"
# include "core.hpp"
# include "bot.hpp"
# include "channel.hpp"
# include "ACommand.hpp"
# include "nickname.hpp"
# include "name.hpp"
# include "pass.hpp"
# include "join.hpp"
# include "msg.hpp"
# include "quit.hpp"
# include "part.hpp"
# include "mode.hpp"
# include "kick.hpp"
# include "invite.hpp"
# include "topic.hpp"
# include "ping.hpp"
# include "whois.hpp"
# include "msg_all.hpp"

#endif
