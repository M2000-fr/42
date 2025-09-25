/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:32:34 by mechard           #+#    #+#             */
/*   Updated: 2025/02/13 14:14:57 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook() : contactCount(0) {}

void PhoneBook::addContact() {
    static int index = 0;
    std::cout << "Adding a new contact..." << std::endl;
    contacts[index % 8].setContact(); // Remplace l'ancien contact si besoin
    index++;
    if (contactCount < 8)
        contactCount++;
}

void PhoneBook::searchContacts() const
{
    int  i;
    int  index;
    
    if (contactCount == 0) 
	{
        std::cout << "❌ No contacts in the PhoneBook." << std::endl;
        return;
    }
    
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    
    i = -1;
    while (++i < contactCount)
        contacts[i].displayShortInfo(i);
    
    while (true)
    {
        std::cout << "Enter an index to view details: ";
        std::string input;
		std::getline(std::cin, input);
        if (input.empty())
		{
            std::cout << "Returning to main menu..." << std::endl;
			return;
		}
        i = -1;
        while ((size_t)++i < input.length())
            if (!std::isdigit(input[i]))
                break;
        index = std::atoi(input.c_str());
        if (index < 0 || (index >= contactCount && index <= 7))
		{
            std::cout << "❌ Invalid index" << std::endl; 
			return;
		}
		else if (index > 7)
		{
			std::cout << "❌ The phonebook can't have more than 8 contact !" << std::endl;
			return;
		}
        else
            contacts[index].displayContact();
    }
}
