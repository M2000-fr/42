/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_irc.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:29:22 by mechard           #+#    #+#             */
/*   Updated: 2025/07/16 13:29:22 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_IRC_HPP
# define MSG_IRC_HPP

# include "irc.hpp"

/* INFORMATION MESSAGES - WHITE COLOR*/

/*---------------------STD-------------------*/
# ifndef INFOS
#  define INFOS		 		1 /* Debug standard flag set to 1 for dislpay */
# endif

# define PRINT_INFOS(MSG)	(INFOS == 1 && g_flag == 1 ? (static_cast<void>(std::cout << MSG << std::endl)) : (void)0)

# define SERVER_INFOS		STANDARD UNDERLINE WHITE << "informations:" << RESET << " " << STANDARD UNDERLINE WHITE << "server:\n" << RESET << STANDARD WHITE << " port     : " << RESET << BOLD WHITE << server.getPort() << STANDARD WHITE << "\n password : " << BOLD WHITE << server.getPassword() << RESET
# define CLIENT_CONNE		STANDARD UNDERLINE WHITE << "informations:" << RESET << " " << STANDARD UNDERLINE WHITE << "connection:" << RESET << BOLD WHITE << " Client connected (" << fd << ")" << RESET
# define CLIENT_DISCO		STANDARD UNDERLINE WHITE << "informations:" << RESET << " " << STANDARD UNDERLINE WHITE << "disconnection:" << RESET << BOLD WHITE << " Client disconnected (" << fd << ")" << RESET
# define PM_DATA			STANDARD UNDERLINE WHITE << "informations:" << RESET << " " << STANDARD UNDERLINE WHITE << "PolManager data:" << RESET << BOLD WHITE << " Received data from fd " << fd << ": " << buff << RESET
# define CH_DATA			STANDARD UNDERLINE WHITE << "informations:" << RESET << " " << STANDARD UNDERLINE WHITE << "channel data:" << RESET << BOLD WHITE << " [" << toConnect->getUsers().size() << "] user connected" << RESET
# define KICK_DATA			STANDARD UNDERLINE WHITE << "informations:" << RESET << " " << STANDARD UNDERLINE WHITE << "channel data:" << RESET << BOLD WHITE << " " << this->_target->getUser() << " <" << this->_target->getNick() << "> has been kicked by " << this->_setter->getUser() << " <" << this->_setter->getNick() << "> for " << this->_spltcmd[3] << RESET
# define SERVER_INFOS		STANDARD UNDERLINE WHITE << "informations:" << RESET << " " << STANDARD UNDERLINE WHITE << "server:\n" << RESET << STANDARD WHITE << " port     : " << RESET << BOLD WHITE << server.getPort() << STANDARD WHITE << "\n password : " << BOLD WHITE << server.getPassword() << RESET
# define CLIENT_CONNE		STANDARD UNDERLINE WHITE << "informations:" << RESET << " " << STANDARD UNDERLINE WHITE << "connection:" << RESET << BOLD WHITE << " Client connected (" << fd << ")" << RESET
# define CLIENT_DISCO		STANDARD UNDERLINE WHITE << "informations:" << RESET << " " << STANDARD UNDERLINE WHITE << "disconnection:" << RESET << BOLD WHITE << " Client disconnected (" << fd << ")" << RESET
# define PM_DATA			STANDARD UNDERLINE WHITE << "informations:" << RESET << " " << STANDARD UNDERLINE WHITE << "PolManager data:" << RESET << BOLD WHITE << " Received data from fd " << fd << ": " << buff << RESET
# define CH_DATA			STANDARD UNDERLINE WHITE << "informations:" << RESET << " " << STANDARD UNDERLINE WHITE << "channel data:" << RESET << BOLD WHITE << " [" << toConnect->getUsers().size() << "] user connected" << RESET
# define KICK_DATA			STANDARD UNDERLINE WHITE << "informations:" << RESET << " " << STANDARD UNDERLINE WHITE << "channel data:" << RESET << BOLD WHITE << " " << this->_target->getUser() << " <" << this->_target->getNick() << "> has been kicked by " << this->_setter->getUser() << " <" << this->_setter->getNick() << "> for " << this->_spltcmd[3] << RESET
// mode flag
# define MODE_I				STANDARD UNDERLINE WHITE << "informations:" << RESET << " " << STANDARD UNDERLINE WHITE << "mode:" << RESET << BOLD WHITE << " Switch to \"i\" mode" << RESET
# define MODE_T				STANDARD UNDERLINE WHITE << "informations:" << RESET << " " << STANDARD UNDERLINE WHITE << "mode:" << RESET << BOLD WHITE << " Switch to \"t\" mode" << RESET
# define MODE_K				STANDARD UNDERLINE WHITE << "informations:" << RESET << " " << STANDARD UNDERLINE WHITE << "mode:" << RESET << BOLD WHITE << " Switch to \"k\" mode" << RESET
# define MODE_O				STANDARD UNDERLINE WHITE << "informations:" << RESET << " " << STANDARD UNDERLINE WHITE << "mode:" << RESET << BOLD WHITE << " Switch to \"o\" mode" << RESET
# define MODE_L				STANDARD UNDERLINE WHITE << "informations:" << RESET << " " << STANDARD UNDERLINE WHITE << "mode:" << RESET << BOLD WHITE << " Switch to \"l\" mode" << RESET
# define MODE_B				STANDARD UNDERLINE WHITE << "informations:" << RESET << " " << STANDARD UNDERLINE WHITE << "mode:" << RESET << BOLD WHITE << " Switch to \"b\" mode" << RESET

/* ERROR MESSAGES - RED COLOR */

# ifndef ERROR
#  define ERROR 			1 /* Error flag set to 0 (not dislpay !)*/
# endif

# define PRINT_ERR(MSG)		(ERROR == 1 && g_flag == 1 ? (static_cast<void>(std::cerr << MSG << std::endl)) : (void)0)

# define ERROR_NBARGS		STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "./ircserv:" << BOLD UNDERLINE RED " <port>" << RESET << " " << BOLD UNDERLINE RED << "<password>" << RESET
# define ERROR_INVARG		STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "invalid argument:" << RESET <<  BOLD RED << " NULL" << RESET
# define ERROR_INVPOR		STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "invalid argument:" << RESET <<  BOLD RED << " non-numeric argument for port" << RESET
# define ERROR_OVEPOR		STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "invalid argument:" << RESET <<  BOLD RED << " port value overflow" << RESET
# define ERROR_ORAPOR		STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "invalid argument:" << RESET <<  BOLD RED << " port not in range [0-65535]" << RESET
# define ERROR_EMPTYN		STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "invalid argument:" << RESET <<  BOLD RED << " Nickname cannot be empty" << RESET
# define ERROR_ANONYM		STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "invalid argument:" << RESET <<  BOLD RED << " Nickname cannot be \"anonymous\"" << RESET
# define ERROR_NTLONG		STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "invalid argument:" << RESET <<  BOLD RED << " Nickname is too long" << RESET
# define ERROR_SNICKN		STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "invalid argument:" << RESET <<  BOLD RED << " The nickname are the same" << RESET
# define ERROR_SOCKET		STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "socket:" << RESET <<  BOLD RED << " FD initialization failed" << RESET
# define ERROR_LISTEN		STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "socket:" << RESET <<  BOLD RED << " listen() failed" << RESET
# define ERROR_BIND			STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "socket:" << RESET <<  RESET <<  BOLD RED << " bind() failed" << RESET
# define ERROR_POLLTO		STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "poll:" << RESET <<  BOLD RED << " poll error" << RESET
# define ERROR_POLLAC		STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "poll:" << RESET <<  BOLD RED << " accept error" << RESET
# define ERROR_NICKIA		STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "nickname:" << RESET <<  BOLD RED << " Invalid arguments (see warning message)" << RESET
# define ERROR_PRIVIA		STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "privmsg:" << RESET <<  BOLD RED << " Invalid arguments (see warning message)" << RESET
# define ERROR_INVTIA		STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "invite:" << RESET <<  BOLD RED << " Invalid arguments (see warning message)" << RESET
# define ERROR_JOINIA		STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "join:" << RESET <<  BOLD RED << " Invalid arguments (see warning message)" << RESET
# define ERROR_KICKIA		STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "kick:" << RESET <<  BOLD RED << " Invalid arguments (see warning message)" << RESET
# define ERROR_NAMEIA		STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "name:" << RESET <<  BOLD RED << " Invalid arguments (see warning message)" << RESET
# define ERROR_MODEIA		STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "mode:" << RESET <<  BOLD RED << " Invalid arguments (see warning message)" << RESET
# define ERROR_PASSIA		STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "pass:" << RESET <<  BOLD RED << " Invalid arguments (see warning message)" << RESET
# define ERROR_PASSER		STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "pass:" << RESET <<  BOLD RED << " An error as occured in \"Pass::executeCmd\"" << RESET
# define ERROR_QUITIA		STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "quit:" << RESET <<  BOLD RED << " Invalid arguments (see warning message)" << RESET
# define ERROR_PARTER		STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "part:" << RESET <<  BOLD RED << " An error as occured in \"Part::executeCmd\"" << RESET
# define ERROR_TOPIER		STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "topic:" << RESET << BOLD RED << " An error as occured in Topic constructor" << RESET
# define ERROR_BOTPRE		STANDARD UNDERLINE RED << "error:" << RESET << " " << STANDARD UNDERLINE RED << "bot:" << RESET << BOLD RED << " Command name should start with an '!'" << RESET

/* WARNING MESSAGES - YELLOW COLOR */

# ifndef WARNING
#  define WARNING 			1 /* Warning flag set to 0 (not dislpay !)*/
# endif

# define PRINT_WARNING(MSG)	(WARNING == 1 && g_flag == 1 ? (static_cast<void>(std::cout << MSG << std::endl)) : (void)0)

// Nickname Command //
# define WARNING_NICKWA		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "nickname:" << RESET <<  BOLD YELLOW << " Wrong number arguments" << RESET
# define WARNING_NICKUS		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "nickname:" << RESET <<  BOLD YELLOW << " Already used " << RESET
// Name Command //
# define WARNING_NAMEWA		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "name:" << RESET <<  BOLD YELLOW << " Wrong number arguments" << RESET
# define WARNING_NAMEAS		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "name:" << RESET <<  BOLD YELLOW << " Name already set" << RESET
// PrivMsg Command //
# define WARNING_CHANNF		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "privmsg:" << RESET <<  BOLD YELLOW << " Channel not found" << RESET
# define WARNING_USERNC		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "privmsg:" << RESET <<  BOLD YELLOW << " User not in channel" << RESET
# define WARNING_USERNF		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "privmsg:" << RESET <<  BOLD YELLOW << " User not found" << RESET
# define WARNING_PRIVEA		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "privmsg:" << RESET <<  BOLD YELLOW << " Not enough arguments" << RESET
// Invite Command //
# define WARNING_INVTWA		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "invite:" << RESET <<  BOLD YELLOW << " Wrong number arguments" << RESET
# define WARNING_INVTUC		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "invite:" << RESET <<  BOLD YELLOW << " Unknown channel" << RESET
# define WARNING_INVTNI		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "invite:" << RESET <<  BOLD YELLOW << " No needs to invite" << RESET
# define WARNING_INVTSN		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "invite:" << RESET <<  BOLD YELLOW << " No user in server name" << RESET
# define WARNING_INVTAR		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "invite:" << RESET <<  BOLD YELLOW << " User already registered" << RESET
# define WARNING_INVTAI		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "invite:" << RESET <<  BOLD YELLOW << " User already invited" << RESET
# define WARNING_INVTOP		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "invite:" << RESET <<  BOLD YELLOW << " Need to be op to invite someone" << RESET
// Join Command //
# define WARNING_JOINEA		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "join:" << RESET <<  BOLD YELLOW << " Not enough arguments" << RESET
# define WARNING_JOINUU		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "join:" << RESET <<  BOLD YELLOW << " User not registered" << RESET
# define WARNING_JOINAC		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "join:" << RESET <<  BOLD YELLOW << " Already in the channel" << RESET
# define WARNING_JOINIO		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "join:" << RESET <<  BOLD YELLOW << " Channel is invite-only. User not invited" << RESET
# define WARNING_JOINCF		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "join:" << RESET <<  BOLD YELLOW << " Channel is full" << RESET
# define WARNING_JOINWP		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "join:" << RESET <<  BOLD YELLOW << " Wrong password" << RESET
// Kick Command //
# define WARNING_KICKEA		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "kick:" << RESET <<  BOLD YELLOW << " Not enough arguments" << RESET
# define WARNING_KICKEC		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "kick:" << RESET <<  BOLD YELLOW << " No existing channel" << RESET
# define WARNING_KICKEU		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "kick:" << RESET <<  BOLD YELLOW << " No existing user in this channel" << RESET
# define WARNING_KICKRK		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "kick:" << RESET <<  BOLD YELLOW << " No right to kick someone (need to be op)" << RESET
# define WARNING_KICKNO		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "kick:" << RESET <<  BOLD YELLOW << " Can't kick the owner of the channel" << RESET
// Mode Command //
# define WARNING_MODEWA		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "mode:" << RESET <<  BOLD YELLOW << " Wrong number of arguments" << RESET
# define WARNING_MODEUU		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "mode:" << RESET <<  BOLD YELLOW << " User not registered" << RESET
# define WARNING_MODEUC		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "mode:" << RESET <<  BOLD YELLOW << " Unknown channel" << RESET
# define WARNING_MODEOP		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "mode:" << RESET <<  BOLD YELLOW << " Need to be op to use mode" << RESET
# define WARNING_MODEWF		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "mode:" << RESET <<  BOLD YELLOW << " Unknown mode flag. Try i,t,k,o,l" << RESET
// Pass Command //
# define WARNING_PASSWA		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "pass:" << RESET <<  BOLD YELLOW << " Wrong number arguments" << RESET
# define WARNING_PASSWP		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "pass:" << RESET <<  BOLD YELLOW << " Wrong password" << RESET
# define WARNING_PASSAS		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "pass:" << RESET <<  BOLD YELLOW << " Password already set" << RESET
// Quit Command //
# define WARNING_QUITWA		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "quit:" << RESET <<  BOLD YELLOW << " Wrong number arguments" << RESET
# define WARNING_QUITNF		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "quit:" << RESET <<  BOLD YELLOW << " User not found" << RESET
// Part Command //
# define WARNING_PARTWA		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "part:" << RESET <<  BOLD YELLOW << " Wrong number arguments" << RESET
# define WARNING_PARTCN		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "part:" << RESET <<  BOLD YELLOW << " No channel found with " << this->_spltcmd[1] << " name." << RESET
# define WARNING_PARTUN		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "part:" << RESET <<  BOLD YELLOW << " Part: User " << this->_setter->getNick() << " not in channel " << this->_target->getName() << RESET
// Topic Command //
# define WARNING_TOPIWA		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "topic:" << RESET <<  BOLD YELLOW << " Wrong number of arguments" << RESET
# define WARNING_TOPINC		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "topic:" << RESET <<  BOLD YELLOW << " No channel to change" << RESET
# define WARNING_TOPINO		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "topic:" << RESET <<  BOLD YELLOW << " Need to be op to use mode" << RESET
# define WARNING_TOPINT		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "topic:" << RESET <<  BOLD YELLOW << " Need a new topic to change" << RESET
// Bot Command //
# define WARNING_BOTAUS		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "bot:" << RESET <<  BOLD YELLOW << " Command name already used" << RESET
# define WARNING_BOTCUK		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "bot:" << RESET <<  BOLD YELLOW << " Command unknown" << RESET
# define WARNING_BOTERF		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "bot:" << RESET <<  BOLD YELLOW << " An error as occured in find() function (lines 89)" << RESET
# define WARNING_BOTADD		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "bot:" << RESET <<  BOLD YELLOW << " An error as occured in add function (lines 137)" << RESET
# define WARNING_BOTRME		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "bot:" << RESET <<  BOLD YELLOW << " An error as occured in rm function (lines 147)" << RESET
# define WARNING_BOTMOP		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "bot:" << RESET <<  BOLD YELLOW << " Need to be op to use the bot" << RESET
# define WARNING_BOTHPR		STANDARD UNDERLINE YELLOW << "warning:" << RESET << " " << STANDARD UNDERLINE YELLOW << "bot:" << RESET <<  BOLD YELLOW << " Command !help is protected" << RESET

/* DEBUG MESSAGES - MAGENTA COLOR*/

/*---------------------STD-------------------*/
# ifndef DEBUG_STD
#  define DEBUG_STD 		1 /* Debug standard flag set to 0 (not dislpay !)*/
# endif

# define PRINT_DEBUG(MSG)	(DEBUG_STD == 1 && g_flag == 1 ? (static_cast<void>(std::cout << MSG << std::endl)) : (void)0)

# define BEGIN_SERVER		STANDARD UNDERLINE MAGENTA << "\ndebug:" << RESET << " " << STANDARD UNDERLINE MAGENTA << "standard:" << RESET <<  BOLD STANDARD MAGENTA << " BEGIN\n" << RESET
# define END_SERVER			STANDARD UNDERLINE MAGENTA << "\n\ndebug:" << RESET << " " << STANDARD UNDERLINE MAGENTA << "standard:" << RESET <<  BOLD STANDARD MAGENTA << " END" << RESET
# define DEBUG_NICK			STANDARD UNDERLINE MAGENTA << "debug:" << RESET << " " << STANDARD UNDERLINE MAGENTA << "standard:" << RESET << BOLD STANDARD MAGENTA << " Setting nickname to " << _spltcmd[1] << RESET

/*--CONSTRUCTOR, DESTRUCTOR, GETERS, SETERS--*/

# ifndef DEBUG_METHOD
#  define DEBUG_METHOD		1 /* Debug constructor, destructor, getters and setters flag set to 0 (not dislpay !) */
# endif

# define PRINT_METHOD(MSG)	(DEBUG_METHOD == 1 && g_flag == 1 ? (static_cast<void>(std::cout << MSG << std::endl)) : (void)0)

// Server //
# define SERVER_CONST		STANDARD UNDERLINE MAGENTA << "debug:" << RESET << " " << STANDARD UNDERLINE MAGENTA << "method:" << RESET << BOLD MAGENTA << " Server constructor called" << RESET
# define SERVER_DESTR		STANDARD UNDERLINE MAGENTA << "debug:" << RESET << " " << STANDARD UNDERLINE MAGENTA << "method:" << RESET << BOLD MAGENTA << " Server destructor called" << RESET
// User //
# define USER_CONSTRU		STANDARD UNDERLINE MAGENTA << "debug:" << RESET << " " << STANDARD UNDERLINE MAGENTA << "method:" << RESET << BOLD MAGENTA << " User constructor called" << RESET
# define USER_DESTRUC		STANDARD UNDERLINE MAGENTA << "debug:" << RESET << " " << STANDARD UNDERLINE MAGENTA << "method:" << RESET << BOLD MAGENTA << " User destructor called" << RESET
// PollManager //
# define PM_CONSTRUCT		STANDARD UNDERLINE MAGENTA << "debug:" << RESET << " " << STANDARD UNDERLINE MAGENTA << "method:" << RESET << BOLD MAGENTA << " PollManager constructor called" << RESET
# define PM_DESTRUCTO		STANDARD UNDERLINE MAGENTA << "debug:" << RESET << " " << STANDARD UNDERLINE MAGENTA << "method:" << RESET << BOLD MAGENTA << " PollManager destructor called" << RESET
// ACommand //
# define AC_CONSTRUCT		STANDARD UNDERLINE MAGENTA << "debug:" << RESET << " " << STANDARD UNDERLINE MAGENTA << "method:" << RESET << BOLD MAGENTA << " ACommand constructor called" << RESET
# define AC_DESTRUCTO		STANDARD UNDERLINE MAGENTA << "debug:" << RESET << " " << STANDARD UNDERLINE MAGENTA << "method:" << RESET << BOLD MAGENTA << " ACommand destructor called" << RESET
// Bot //
# define BOT_CONSTRUCT		STANDARD UNDERLINE MAGENTA << "debug:" << RESET << " " << STANDARD UNDERLINE MAGENTA << "method:" << RESET << BOLD MAGENTA << " Bot constructor called" << RESET
# define BOT_DESTRUCTO		STANDARD UNDERLINE MAGENTA << "debug:" << RESET << " " << STANDARD UNDERLINE MAGENTA << "method:" << RESET << BOLD MAGENTA << " Bot destructor called" << RESET
// Channel //
# define CHA_SEARCHCHA		STANDARD UNDERLINE MAGENTA << "debug:" << RESET << " " << STANDARD UNDERLINE MAGENTA << "channel:" << RESET << BOLD MAGENTA << " Searching channel -> " << name << RESET
# define CHA_COMPARCHA		STANDARD UNDERLINE MAGENTA << "debug:" << RESET << " " << STANDARD UNDERLINE MAGENTA << "channel:" << RESET << BOLD MAGENTA << " Compared to channel -> " << (*it)->getName() << RESET
# define CHANNEL_CONSTRUCT		STANDARD UNDERLINE MAGENTA << "debug:" << RESET << " " << STANDARD UNDERLINE MAGENTA << "method:" << RESET << BOLD MAGENTA << " Channel constructor called" << RESET
# define CHANNEL_DESTRUCTO		STANDARD UNDERLINE MAGENTA << "debug:" << RESET << " " << STANDARD UNDERLINE MAGENTA << "method:" << RESET << BOLD MAGENTA << " Channel destructor called" << RESET

/* SUCCESS - GREEN COLOR*/

# ifndef SUCCESS
#  define SUCCESS 			1 /* Success flag set to 0 (not dislpay !) */
# endif

# define PRINT_SUCCESS(MSG)	(SUCCESS == 1 && g_flag == 1 ? (static_cast<void>(std::cout << MSG << std::endl)) : (void)0)

# define SUCCESS_START		STANDARD UNDERLINE GREEN << "success:" << RESET << " " << STANDARD UNDERLINE GREEN << "server:" << RESET << BOLD GREEN << " start" << RESET
# define SUCCESS_INVIT		STANDARD UNDERLINE GREEN << "success:" << RESET << " " << STANDARD UNDERLINE GREEN << "invit:" << RESET << BOLD GREEN << " USER : " << this->_target->getNick() << " HAS BEEN INVITED" << RESET
# define SUCCESS_JCHAN		STANDARD UNDERLINE GREEN << "success:" << RESET << " " << STANDARD UNDERLINE GREEN << "join:" << RESET << BOLD GREEN << " " << this->_setter->getNick() << " joined " << chanName << RESET
# define SUCCESS_JCRCH		STANDARD UNDERLINE GREEN << "success:" << RESET << " " << STANDARD UNDERLINE GREEN << "join:" << RESET << BOLD GREEN << " Channel " << chanName << " created and joined by " << this->_setter->getNick() << RESET
# define SUCCESS_PARNR		STANDARD UNDERLINE GREEN << "success:" << RESET << " " << STANDARD UNDERLINE GREEN << "part:" << RESET << BOLD GREEN << " <" << this->_target->getName() << "> channel left by " <<  this->_setter->getNick() << RESET
# define SUCCESS_PARWR		STANDARD UNDERLINE GREEN << "success:" << RESET << " " << STANDARD UNDERLINE GREEN << "part:" << RESET << BOLD GREEN << " <" << this->_target->getName() << "> because " << reason << RESET
# define SUCCESS_TOPIC		STANDARD UNDERLINE GREEN << "success:" << RESET << " " << STANDARD UNDERLINE GREEN << "topic:" << RESET << BOLD GREEN << "Channel's topic has been changed for -> " << this->_channel->getTopic() << RESET

/* END MESSAGES - GREEN for SUCCESS and RED for FAILED*/

# ifndef END
#  define END 			1 /* End flag set to 1 for dislpay */
# endif

# define PRINT_END(MSG)		(END == 1 && g_flag == 1 ? (static_cast<void>(std::cout << MSG << std::endl)) : (void)0)

# define SUCCESS_END 		STANDARD UNDERLINE GREEN << "\nend:" << RESET << STANDARD GREEN << " Everything seems to be okay ! " << RESET << BOLD UNDERLINE GREEN << "Congrats" << RESET << STANDARD GREEN <<  " !\n" << RESET
# define FAILED_END 		STANDARD UNDERLINE RED << "\nend:" << RESET << STANDARD RED << " You are at the end but " << RESET << BOLD RED << "a failed as occured !" << RESET

#endif
