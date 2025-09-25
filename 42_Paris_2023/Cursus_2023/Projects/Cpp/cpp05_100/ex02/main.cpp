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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	
	std::cout << BOLD YELLOW << "-------------------------------------- Tests --------------------------------------" << std::endl;
    // ---- Tests existants ----

    try
	{
        std::cout << STANDARD YELLOW << "------------------------ Test 1 : Création de Bureaucrates ------------------------" << std::endl;
        // Création des Bureaucrates 'Arthur Dent' et 'Humma Kavula'
        Bureaucrat Arthur("Arthur Dent", 1);
        std::cout << Arthur << std::endl;
        Bureaucrat Humma("Humma Kavula", 150);
        std::cout << Humma << std::endl;

        std::cout << STANDARD YELLOW << "\n------------------------- Test 2 : Création de Formulaires ------------------------" << std::endl;
        // Création des formulaires 'Home', 'Bender' et 'Marvin'
        ShrubberyCreationForm shrub("Home");
        std::cout << shrub << std::endl;
        RobotomyRequestForm robot("Bender");
        std::cout << robot << std::endl;
        PresidentialPardonForm pardon("Marvin");
        std::cout << pardon << std::endl;

        std::cout << STANDARD YELLOW << "\n------------------------- Test 3 : Signature de formulaire ------------------------" << std::endl;
        // Signatures des formlaires précédemment créé. 1 test avec Humma car low grade puis signature avec Arthur
        Humma.signForm(shrub);
        Arthur.signForm(shrub);
        Arthur.signForm(robot);
        Arthur.signForm(pardon);
        Arthur.signForm(pardon);
    }
    catch (std::exception &e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // ---- Tests supplémentaires ----

    try
	{
        // Initialisation des variables et signature des formulaires
        Bureaucrat Arthur("Arthur Dent", 1);
        Bureaucrat Humma("Humma Kavula", 150);
        ShrubberyCreationForm shrub("Home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Marvin");

        std::cout << STANDARD YELLOW << "\n------------------------- Test 4 : Éxécution de formulaire ------------------------" << std::endl;
        // Éxécution des formlaires précédemment signé. 1 test avec Humma car low grade, 1 test avec un nouveau formulaire non-signé puis éxécution des formulaires signés avec Arthur
        Arthur.executeForm(shrub);
        Arthur.signForm(shrub);
        Arthur.signForm(robot);
        Arthur.signForm(pardon);
        Humma.executeForm(shrub);
        Arthur.executeForm(shrub);
        Arthur.executeForm(robot);
        Arthur.executeForm(pardon);

        std::cout << STANDARD YELLOW << "\n---------------- Test 5 : Éxécution multiples de RobotomyRequest ------------------" << std::endl;
        // Exécution multiples de RobotomyRequest pour vérifier la ramdomité de la fonction
        RobotomyRequestForm robot3("Betelgeuse");
        Arthur.signForm(robot3);
        std::cout << STANDARD YELLOW << "Executing RobotomyRequestForm multiple times to test randomness:" << std::endl;
        for (int i = 0; i < 5; i++)
        {
            Arthur.executeForm(robot3);
        }

        std::cout << STANDARD YELLOW << "\n-------------------- Test 6 : Éxécution avec des grades limites -------------------" << std::endl;
        // Signature avec un bureaucrate de grade limite et execution avec un bureaucrate de grade limite
        PresidentialPardonForm pardon3("Pan Galactic Gargle Blaster");
        Bureaucrat Fench("Fenchurch", 25);
        std::cout << Fench << std::endl;
        std::cout << pardon3 << std::endl;
        Fench.signForm(pardon3);
        Bureaucrat Eddie("Eddie", 5);
        std::cout << Eddie << std::endl;
        std::cout << pardon3 << std::endl;
        Eddie.executeForm(pardon3);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
