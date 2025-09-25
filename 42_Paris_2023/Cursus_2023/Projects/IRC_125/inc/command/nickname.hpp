/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nickname.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:02:43 by mechard           #+#    #+#             */
/*   Updated: 2025/07/24 15:02:43 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef NICKNAME_HPP
# define NICKNAME_HPP

class Nick : public ACommand
{
	public:
		Nick(Server *sInfs, std::vector<std::string> spltCmd, User *sender) : ACommand(sInfs, spltCmd, sender) {executeCmd();}
		void executeCmd(void);
		int checkArgs(void) const;
};

#endif