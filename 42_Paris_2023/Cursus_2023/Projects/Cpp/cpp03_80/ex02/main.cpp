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
#include "FragTrap.hpp"

int main()
{
    std::cout << "\n--- Test avec ClapTrap ---" << std::endl;
    ClapTrap clap("Clappy");
    clap.attack("Cible1");
    clap.takeDamage(3);
    clap.beRepaired(2);

    std::cout << "\n--- Test avec ScavTrap ---" << std::endl;
    ScavTrap scav("Scavy");
    scav.attack("Cible2");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();

    std::cout << "\n--- Test avec FragTrap ---" << std::endl;
    FragTrap frag("Fraggy");
    frag.attack("Cible3");
    frag.takeDamage(15);
    frag.beRepaired(5);
    frag.highFivesGuys();

    return 0;
}
