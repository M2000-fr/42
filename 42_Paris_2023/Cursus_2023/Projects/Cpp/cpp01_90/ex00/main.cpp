/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:22:09 by mechard           #+#    #+#             */
/*   Updated: 2025/04/24 13:11:28 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(int ac, char **av)
{
    if (ac == 2)
    {
        Zombie* heapZombie = newZombie(av[1]);
        heapZombie->announce();
        delete heapZombie;
    }
    else
    {
        Zombie* heapZombie = newZombie("Heap_Zombie");
        heapZombie->announce();
        delete heapZombie;
    }
    
    randomChump("Stack_Zombie");

    return 0;
}
