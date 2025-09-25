/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:29:44 by mechard           #+#    #+#             */
/*   Updated: 2025/03/27 00:29:44 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;
    data.number = 42;
    data.letter = 'A';

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << BOLD CYAN UNDERLINE CYAN << "Adresse originale" << RESET << " : " << UNDERLINE YELLOW << &data << RESET << std::endl;
    std::cout << BOLD CYAN UNDERLINE CYAN << "Valeur sérialisée" << RESET << " : " << UNDERLINE YELLOW << raw << RESET << std::endl;

    Data* newData = Serializer::deserialize(raw);
    std::cout << BOLD CYAN UNDERLINE CYAN << "Adresse désérialisée" << RESET << " : " << UNDERLINE YELLOW << newData << RESET << std::endl;
    std::cout << BOLD CYAN UNDERLINE CYAN << "Données récupérées" << RESET << " : number = " << STANDARD YELLOW << newData->number 
              << RESET << ", letter = " << STANDARD YELLOW << newData->letter << RESET << std::endl;

    if (newData == &data)
        std::cout << BOLD GREEN << "La sérialisation/désérialisation a réussi." << RESET << std::endl;
    else
        std::cout << BOLD RED << "Erreur dans la sérialisation/désérialisation." << RESET << std::endl;

    return 0;
}
