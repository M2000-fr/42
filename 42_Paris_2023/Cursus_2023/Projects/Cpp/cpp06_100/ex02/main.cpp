/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:52:16 by mechard           #+#    #+#             */
/*   Updated: 2025/03/27 01:52:16 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

int main()
{
    Base* p = generate();
    
    std::cout << BOLD CYAN UNDERLINE CYAN << "Identification via pointeur" << RESET << ": " << BOLD GREEN;
    identify(p);
    std::cout << RESET << std::endl;
    
    std::cout << BOLD CYAN UNDERLINE CYAN << "Identification via référence" << RESET << ": " << BOLD GREEN;
    identify(*p);
    std::cout << RESET << std::endl;
    
    delete p;
    return 0;
}
