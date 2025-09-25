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
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

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

        std::cout << STANDARD YELLOW << "\n------------------------- Test 4 : Éxécution de formulaire ------------------------" << std::endl;
        // Éxécution des formlaires précédemment signé. 1 test avec Humma car low grade, 1 test avec un nouveau formulaire non-signé puis éxécution des formulaires signés avec Arthur
        Humma.executeForm(shrub);
        ShrubberyCreationForm false_sign("false");
        Arthur.executeForm(false_sign);
        Arthur.executeForm(shrub);
        Arthur.executeForm(robot);
        Arthur.executeForm(pardon);
    }
    catch (std::exception &e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        // ---- Tests supplémentaires ----
        std::cout << STANDARD YELLOW << "\n-------------- Test 5 : Création répétée de formulaires du même type --------------" << std::endl;
        // Utilisation de l'Intern pour créer deux formulaires identiques.
        Intern intern;
        AForm* formA = intern.makeForm("robotomy request", "Vogon");
        AForm* formB = intern.makeForm("robotomy request", "Vogon");
        std::cout << "Adress formA " << UNDERLINE CYAN BOLD CYAN << formA->getName() << RESET << ": " << UNDERLINE CYAN BOLD CYAN << formA << RESET << std::endl;
        std::cout << "Adress formB " << UNDERLINE CYAN BOLD CYAN << formB->getName() << RESET << ": " << UNDERLINE CYAN BOLD CYAN << formB << RESET << std::endl;
        if (formA && formB && formA != formB)
            std::cout << BOLD GREEN << "Les deux formulaires sont créés distinctement." << RESET << std::endl;
        else
            std::cout << BOLD RED << "Les deux formulaires ne sont pas créés distinctement !" << RESET << std::endl;
        delete formA;
        delete formB;

        std::cout << STANDARD YELLOW << "\n------- Test 6 : Réutilisation de l'Intern pour divers types de formulaires -------" << std::endl;
        // L'intern crée différents types de formulaires avec des cibles variées.
        AForm* form1 = intern.makeForm("shrubbery creation", "Earth");
        AForm* form2 = intern.makeForm("robotomy request", "Mars");
        AForm* form3 = intern.makeForm("presidential pardon", "Jupiter");
        delete form1;
        delete form2;
        delete form3;
        
        std::cout << STANDARD YELLOW << "\n----------------- Test 7 : Re-signature d'un formulaire déjà signé ----------------" << std::endl;
        // Zaphod signe un formulaire de ShrubberyCreationForm et tente de le signer une seconde fois.
        AForm* form = intern.makeForm("shrubbery creation", "Betelgeuse");
        Bureaucrat Zaphod("Zaphod Beeblebrox", 1);
        if(form) {
            Zaphod.signForm(*form);
            Zaphod.signForm(*form);
            Zaphod.executeForm(*form);
        }
        delete form;

        std::cout << STANDARD YELLOW << "\n-------- Test 8 : Exécution d'un formulaire non signé (attendu : exception) -------" << std::endl;
        // Création d'un formulaire sans signature ; l'exécution doit lever une exception.
        AForm* form8 = intern.makeForm("robotomy request", "Gaudeamus");
        Bureaucrat Trillian("Trillian", 1);
        if(form8) {
            Trillian.executeForm(*form8);
        }
        delete form8;
        
        std::cout << STANDARD YELLOW << "\n----------- Test 9 : Exécution avec un bureaucrate de grade insuffisant -----------" << std::endl;
        // Création d'un formulaire de PresidentialPardonForm signé par un bureaucrate compétent,
        // puis tentative d'exécution par un bureaucrate dont le grade est insuffisant.
        AForm* form9 = intern.makeForm("presidential pardon", "Earth");
        Bureaucrat signer("Ford Prefect", 1);
        Bureaucrat executor("Marvin", 150);
        if(form9) {
            signer.signForm(*form9);
            executor.executeForm(*form9);
        }
        delete form9;
        
        std::cout << STANDARD YELLOW << "\n-------------------- Test 10 : Création d'un formulaire inconnu -------------------" << std::endl;
        AForm* formInvalid = intern.makeForm("unknown form", "Nowhere");
        if (!formInvalid)
            std::cout << "Aucun formulaire n'a été créé pour 'unknown form'." << std::endl;
        else
            std::cout << "Un formulaire 'unknown form' a été créé ." << std::endl;
    }
    catch (std::exception &e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
