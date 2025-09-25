/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoigoux <sgoigoux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:22:25 by mechard           #+#    #+#             */
/*   Updated: 2025/03/15 18:05:58 by sgoigoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	
private:
    std::string name;
	
public:
    Zombie(std::string name);
    ~Zombie();
    void announce(void) const;

};

#endif