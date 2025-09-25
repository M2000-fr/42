/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:13:41 by mechard           #+#    #+#             */
/*   Updated: 2025/03/15 19:13:41 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    
    std::string* stringPTR = &brain;
    
    std::string& stringREF = brain;

	std::cout << std::endl;
    std::cout << "Adresse de brain : " << &brain << std::endl;
    std::cout << "Adresse contenue dans stringPTR : " << stringPTR << std::endl;
    std::cout << "Adresse contenue dans stringREF : " << &stringREF << std::endl;

	std::cout << std::endl;

    std::cout << "Valeur de brain : " << brain << std::endl;
    std::cout << "Valeur pointée par stringPTR : " << *stringPTR << std::endl;
    std::cout << "Valeur pointée par stringREF : " << stringREF << std::endl;
	std::cout << std::endl;
    
    return 0;
}