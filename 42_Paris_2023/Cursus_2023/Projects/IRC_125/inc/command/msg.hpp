/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:57:37 by mechard           #+#    #+#             */
/*   Updated: 2025/07/29 12:57:37 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MSG_HPP
# define MSG_HPP

class PrivMsg : public ACommand
{
	public:
		PrivMsg(Server *sInfs, std::vector<std::string> spltCmd, User *setter) : ACommand(sInfs, spltCmd, setter) {executeCmd();}
		void executeCmd(void);
		int checkArgs(void) const;
};

#endif