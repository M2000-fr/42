/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_clt.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:29:22 by mechard           #+#    #+#             */
/*   Updated: 2025/07/16 13:29:22 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_CLT_HPP
# define MSG_CLT_HPP

// Command //
# define CLT_ERRCMD		BOLD RED "error: " + spltCmd[0] + " : Unknown command\n" RESET "\r\n"
// Nickname Command //
# define CLT_NICKIA		BOLD RED "error: nick: Invalid arguments (see warning message)\n" RESET "\r\n"
# define CLT_NICKWA		BOLD YELLOW "warning: nick: Wrong number arguments\n" RESET "\r\n"
# define CLT_NICKUS		BOLD YELLOW "warning: nick: Already used \n" RESET "\r\n"
// Name Command //
# define CLT_NAMEIA		BOLD RED "error: user: Invalid arguments (see warning message)\n" RESET "\r\n"
# define CLT_NAMEWA		BOLD YELLOW "warning: user: Wrong number arguments\n" RESET "\r\n"
# define CLT_NAMEAS		BOLD YELLOW "warning: user: Name already set\n" RESET "\r\n"
// PrivMsg Command //
# define CLT_PRIVIA		BOLD RED "error: privmsg: Invalid arguments (see warning message)\n" RESET "\r\n"
# define CLT_CHANNF		BOLD YELLOW "warning: privmsg: Channel not found\n" RESET "\r\n"
# define CLT_USERNC		BOLD YELLOW "warning: privmsg: User not in channel\n" RESET "\r\n"
# define CLT_USERNF		BOLD YELLOW "warning: privmsg: User not found\n" RESET "\r\n"
# define CLT_PRIVEA		BOLD YELLOW "warning: privmsg: Not enough arguments\n" RESET "\r\n"
// Invite Command //
# define CLT_INVTIA		BOLD RED "error: invite: Invalid arguments (see warning message)\n" RESET "\r\n"
# define CLT_INVTWA		BOLD YELLOW "warning: invite: Wrong number arguments\n" RESET "\r\n"
# define CLT_INVTUC		BOLD YELLOW "warning: invite: Unknown channel\n" RESET "\r\n"
# define CLT_INVTNI		BOLD YELLOW "warning: invite: No needs to invite\n" RESET "\r\n"
# define CLT_INVTSN		BOLD YELLOW "warning: invite: No user in server name\n" RESET "\r\n"
# define CLT_INVTAR		BOLD YELLOW "warning: invite: User already registered\n" RESET "\r\n"
# define CLT_INVTAI		BOLD YELLOW "warning: invite: User already invited\n" RESET "\r\n"
# define CLT_INVTOP		BOLD YELLOW "warning: invite: Need to be op to invite someone\n" RESET "\r\n"
# define CLT_INVTSU		BOLD GREEN "Success !" STANDARD "You've invited " + this->_target->getNick() + "\n" RESET "\r\n"
// Join Command //
# define CLT_JOINIA		BOLD RED "error: join: Invalid arguments (see warning message)\n" RESET "\r\n"
# define CLT_JOINEA		BOLD YELLOW "warning: join: Not enough arguments\n" RESET "\r\n"
# define CLT_JOINUU		BOLD YELLOW "warning: join: User not registered\n" RESET "\r\n"
# define CLT_JOINAC		BOLD YELLOW "warning: join: Already in the channel\n" RESET "\r\n"
# define CLT_JOINIO		BOLD YELLOW "warning: join: Channel is invite-only. User not invited\n" RESET "\r\n"
# define CLT_JOINCF		BOLD YELLOW "warning: join: Channel is full\n" RESET "\r\n"
# define CLT_JOINWP		BOLD YELLOW "warning: join: Wrong password\n" RESET "\r\n"
# define CLT_JOINSU		":" + this->_setter->getPrefix() + " PRIVMSG " + chanName + " :" BOLD GREEN  "success: join: Channel " + chanName + " successfully joined by " + this->_setter->getNick() + "\n" RESET "\r\n"
// Kick Command //
# define CLT_KICKIA		BOLD RED "error: kick: Invalid arguments (see warning message)\n" RESET "\r\n"
# define CLT_KICKEA 	BOLD YELLOW "warning: kick: Not enough arguments\n" RESET "\r\n"
# define CLT_KICKEC 	BOLD YELLOW "warning: kick: No existing channel\n" RESET "\r\n"
# define CLT_KICKEU 	":" + this->_setter->getPrefix() + " PRIVMSG " + _chan->getName() + " :" BOLD YELLOW "warning: kick: No existing user in this channel\n" RESET "\r\n"
# define CLT_KICKRK 	":" + this->_setter->getPrefix() + " PRIVMSG " + _chan->getName() + " :" BOLD YELLOW "warning: kick: No right to kick someone (need to be op)\n" RESET "\r\n"
# define CLT_KICKNO 	":" + this->_setter->getPrefix() + " PRIVMSG " + _chan->getName() + " :" BOLD YELLOW "warning: kick: Can't kick the owner of the channel\n" RESET "\r\n"
// Mode Command //
# define CLT_MODEIA		BOLD RED "error: mode: Invalid arguments (see warning message)\n" RESET "\r\n"
# define CLT_MODEWA		BOLD YELLOW "warning: mode: Wrong number of arguments\n" RESET "\r\n"
# define CLT_MODEUU		BOLD YELLOW "warning: mode: User not registered\n" RESET "\r\n"
# define CLT_MODEUC		BOLD YELLOW "warning: mode: Unknown channel\n" RESET "\r\n"
# define CLT_MODEOP		":" + this->_setter->getPrefix() + " PRIVMSG " + cha->getName() + " :" BOLD YELLOW "warning: mode: Need to be op to use mode\n" RESET "\r\n"
# define CLT_MODEWF		":" + this->_setter->getPrefix() + " PRIVMSG " + cha->getName() + " :" BOLD YELLOW "warning: mode: Unknown mode flag. Try i,t,k,o,l\n" RESET "\r\n"
# define CLT_MODE_I		":" + this->_setter->getPrefix() + " PRIVMSG " + cha->getName() + " :" BOLD WHITE "mode: Switch to \"i\" mode\n" RESET "\r\n"
# define CLT_MODE_T		":" + this->_setter->getPrefix() + " PRIVMSG " + cha->getName() + " :" BOLD WHITE "mode: Switch to \"t\" mode\n" RESET "\r\n"
# define CLT_MODE_K		":" + this->_setter->getPrefix() + " PRIVMSG " + cha->getName() + " :" BOLD WHITE "mode: Switch to \"k\" mode\n" RESET "\r\n"
# define CLT_MODE_O		":" + this->_setter->getPrefix() + " PRIVMSG " + cha->getName() + " :" BOLD WHITE "mode: Switch to \"o\" mode\n" RESET "\r\n"
# define CLT_MODE_L		":" + this->_setter->getPrefix() + " PRIVMSG " + cha->getName() + " :" BOLD WHITE "mode: Switch to \"l\" mode\n" RESET "\r\n"
# define CLT_MODE_B		":" + this->_setter->getPrefix() + " PRIVMSG " + cha->getName() + " :" BOLD WHITE "mode: Switch to \"b\" mode\n" RESET "\r\n"
// Pass Command //
# define CLT_PASSIA		BOLD RED "error: pass: Command pass failed\n\n" RESET "\r\n"
# define CLT_PASSWA		BOLD YELLOW "warning: pass: Wrong number of arguments\n\n" RESET BOLD UNDERLINE YELLOW "usage:\n" RESET BOLD YELLOW "warning:  pass <password>)\n\n" RESET "\r\n"
# define CLT_PASSAS		BOLD YELLOW "warning: pass: Password already set\n\n" RESET "\r\n"
# define CLT_PASSWP		BOLD YELLOW "warning: pass: Wrong password\n\n" RESET "\r\n"
// Quit Command //
# define CLT_QUITIA		BOLD RED "error: quit: Command pass failed\n\n" RESET "\r\n"
# define CLT_QUITWA		BOLD YELLOW "warning: quit: Wrong number arguments\n" RESET "\r\n"
# define CLT_QUITNF		BOLD YELLOW "warning: quit: User not found\n" RESET "\r\n"
// Part Command //
# define CLT_PARTER		BOLD RED "error: part: Command pass failed\n\n" RESET "\r\n"
# define CLT_PARTWA		BOLD YELLOW "warning: part: Wrong number arguments\n" RESET "\r\n"
# define CLT_PARTCN		BOLD YELLOW "warning: part: No channel found with " + this->_spltcmd[1] + " name.\n" RESET "\r\n"
# define CLT_PARTUN		BOLD YELLOW "warning: part: User " + this->_setter->getUser() + " not in channel " + this->_target->getName() + RESET "\r\n"
# define CLT_PARTSU		BOLD GREEN "part: You've successfully left the channel\n" RESET "\r\n"
// Topic Command //
# define CLT_TOPIER		BOLD RED "error: topic: An error as occured in Topic constructor\n" RESET "\r\n"
# define CLT_TOPIWA		BOLD YELLOW "warning: topic: Wrong number of arguments\n" RESET "\r\n"
# define CLT_TOPINC		BOLD YELLOW "warning: topic: No channel to change\n" RESET "\r\n"
# define CLT_TOPINO		":" + this->_setter->getPrefix() + " PRIVMSG " + _channel->getName() + " :" BOLD YELLOW "warning: topic: Need to be op to use mode\n" RESET "\r\n"
# define CLT_TOPINT		":" + this->_setter->getPrefix() + " PRIVMSG " + _channel->getName() + " :" BOLD YELLOW "warning: topic: Need a new topic to change\n" RESET "\r\n"
# define CLT_TOPISU		":" + this->_setter->getPrefix() + " PRIVMSG " + _channel->getName() + " :" BOLD GREEN "topic: Channel's topic has been changed for -> " + this->_channel->getTopic() + "\n" RESET "\r\n"
// Bot Command //
# define CLT_BOTPRE		":" + setter->getPrefix() + " PRIVMSG " + _channel->getName() + " :" BOLD RED "error: bot: Command name should start with an '!'\n" RESET "\r\n"
# define CLT_BOTMOP		":" + setter->getPrefix() + " PRIVMSG " + _channel->getName() + " :" BOLD YELLOW "warning: bot: Need to be op to use the bot\n" RESET "\r\n"
# define CLT_BOTADD		":" + setter->getPrefix() + " PRIVMSG " + _channel->getName() + " :" BOLD YELLOW "warning: bot: A warning as occured in add function\n" RESET "\r\n"
# define CLT_BOTRME		":" + setter->getPrefix() + " PRIVMSG " + _channel->getName() + " :" BOLD YELLOW "warning: bot: A warning as occured in rm function\n" RESET "\r\n"
// Success Message //
# define SUCCESS_CONNE	STANDARD " :" UNDERLINE GREEN "success:" RESET " " STANDARD UNDERLINE GREEN "connection:" RESET BOLD GREEN " Welcome to the IRC server " + getNick() + "\n" RESET "\r\n"

#endif
