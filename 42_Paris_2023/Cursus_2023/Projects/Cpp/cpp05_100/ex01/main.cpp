/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:32:48 by mechard           #+#    #+#             */
/*   Updated: 2025/03/18 11:32:48 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << BOLD YELLOW << "-------------------------------------- Tests --------------------------------------" << std::endl;

    try
	{
        // ---- Tests existants ----
        std::cout << STANDARD YELLOW << "------------------------ Test 1 : Création de Bureaucrates ------------------------" << std::endl;
        // Création des Bureaucrates 'Arthur Dent' et 'Humma Kavula'
        Bureaucrat Arthur("Arthur Dent", 1);
        std::cout << Arthur << std::endl;
        Bureaucrat Humma("Humma Kavula", 150);
        std::cout << Humma << std::endl;

    }
    catch (std::exception &e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
	{
        // ---- Tests supplémentaires ----
        std::cout << STANDARD YELLOW << "\n------------------------- Test 2 : Création de Formulaires ------------------------" << std::endl;
        // Création des formulaires 'Home', 'Bender' et 'Marvin'
        Form formA("FormA", 100, 100);
        std::cout << formA << std::endl;

        std::cout << STANDARD YELLOW << "\n------------------------- Test 3 : Signature de formulaire ------------------------" << std::endl;
        // Signatures du formlaire précédemment créé. 1 test avec Humma car low grade puis signature avec Arthur
        Bureaucrat Arthur("Arthur Dent", 1);
        Bureaucrat Humma("Humma Kavula", 150);
        std::cout << formA << std::endl;
        Humma.signForm(formA);
        Arthur.signForm(formA);
    }
    catch (std::exception &e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
