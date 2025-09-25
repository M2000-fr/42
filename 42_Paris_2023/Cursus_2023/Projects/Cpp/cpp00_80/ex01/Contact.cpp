/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:20:55 by mechard           #+#    #+#             */
/*   Updated: 2025/02/13 14:48:01 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setContact()
{
    int     nb;
    size_t  i;

    do
	{
        std::cout << "First Name : ";
        if (!std::getline(std::cin, firstName) || firstName.empty())
		{
			if (std::cin.eof()) 
			{
                std::cout << "\n🔴 End of input detected (Ctrl+D). Closing the program." << std::endl;
                exit(1);
			}
            std::cout << "❌ This field cannot be empty!" << std::endl;
		}
    } while (firstName.empty());

    do
	{
        std::cout << "Last Name : ";
        if (!std::getline(std::cin, lastName) || lastName.empty())
		{
			if (std::cin.eof()) 
			{
                std::cout << "\n🔴 End of input detected (Ctrl+D). Closing the program." << std::endl;
                exit(1);
			}
            std::cout << "❌ This field cannot be empty!" << std::endl;
		}
    } while (lastName.empty());

    do
	{
        std::cout << "Nickname : ";
        if (std::getline(std::cin, nickname) || nickname.empty())
        {
			if (std::cin.eof()) 
			{
                std::cout << "\n🔴 End of input detected (Ctrl+D). Closing the program." << std::endl;
                exit(1);
			}
		    std::cout << "❌ This field cannot be empty!" << std::endl;
		}
    } while (nickname.empty());

    do
	{
        std::cout << "Phone Number : ";
        if (!std::getline(std::cin, phoneNumber))
		{
            if (std::cin.eof())
			{
                std::cout << "\n🔴 End of input detected (Ctrl+D). Closing the program." << std::endl;
                exit(1);
            }
            std::cout << "❌ This field cannot be empty!" << std::endl;
            continue;
        }
        nb = 0;
        i = -1;
        while (++i < phoneNumber.length()) {
            if (std::isdigit(phoneNumber[i]))
                nb++;
            else if (phoneNumber[i] != ' ' && phoneNumber[i] != '.')
                break;
        }

        if (nb != 10)
            std::cout << "❌ Numéro invalide ! Format attendu : 01 23 45 67 89 ou 01.23.45.67.89 ou 0123456789" << std::endl;

    } while (nb != 10);

    do
	{
        std::cout << "Darkest Secret : ";
        std::getline(std::cin, darkestSecret);
        if (darkestSecret.empty())
            std::cout << "❌ This field cannot be empty!" << std::endl;
    } while (darkestSecret.empty());
}


void	Contact::displayContact() const
{
	std::cout << "First Name : " << firstName << std::endl;

	std::cout << "Last Name : " << lastName << std::endl;

	std::cout << "Nickname : " << nickname << std::endl;

	std::cout << "Phone Number : " << phoneNumber << std::endl;

	std::cout << "Darkest secret : " << darkestSecret << std::endl;
}

void	Contact::displayShortInfo(int index) const
{
	std::cout << "|" << std::setw(10) << index << "|";
	std::cout << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0,9) + "." : firstName) << "|";
	std::cout << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0,9) + "." : lastName) << "|";
	std::cout << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0,9) + "." : nickname) << "|" << std::endl;
}
