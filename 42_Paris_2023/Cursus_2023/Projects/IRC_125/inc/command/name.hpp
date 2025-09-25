/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Name.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:02:43 by mechard           #+#    #+#             */
/*   Updated: 2025/07/24 15:02:43 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef NAME_HPP
# define NAME_HPP

class Name : public ACommand
{
	public:
		Name(Server *sInfs, std::vector<std::string> spltCmd, User *sender) : ACommand(sInfs, spltCmd, sender) {executeCmd();}
		void executeCmd(void);
		int checkArgs(void) const;
};

#endif