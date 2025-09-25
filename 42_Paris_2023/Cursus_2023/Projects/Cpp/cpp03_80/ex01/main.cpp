/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:33:32 by mechard           #+#    #+#             */
/*   Updated: 2025/03/16 11:33:32 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    std::cout << "\033[36m";
    std::cout << "\n--- Test avec ClapTrap ---" << std::endl;
    ClapTrap clap("Clappy");
    clap.attack("Cible1");
    clap.takeDamage(3);
    clap.beRepaired(2);
    std::cout << "\033[0m";

    std::cout << "\n--- Test avec ScavTrap ---" << std::endl;
    ScavTrap scav("Scavy");
    std::cout << "\033[32m";
    scav.attack("Cible2");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();
    std::cout << "\033[33m";
    scav.takeDamage(50);
    scav.beRepaired(10);
    scav.takeDamage(50);
    std::cout << "\033[31m";
    scav.beRepaired(10);
    scav.takeDamage(50);
    scav.attack("Cible2");
    scav.guardGate();
    std::cout << "\033[0m";

    return 0;
}
