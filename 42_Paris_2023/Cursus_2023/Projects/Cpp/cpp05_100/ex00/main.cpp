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

int main()
{
    std::cout << BOLD YELLOW << "-------------------------------------- Tests --------------------------------------" << RESET << std::endl;

    try
	{
        Bureaucrat Arthur("Arthur Dent", 2);
        std::cout << "for " << BOLD << BLUE << UNDERLINE << BLUE << Arthur.getName() << RESET << ":\n" << std::endl;
        std::cout << Arthur << std::endl;
        Arthur.incrementGrade();
        std::cout << Arthur << std::endl;
        Arthur.incrementGrade();
    }
    catch (std::exception &e)
	{
        std::cerr << "Arthur: Exception: " << e.what() << std::endl;
	}

    try
	{
        Bureaucrat Sarah("Sarah Connor", 0);
        std::cout << "for " << BOLD << BLUE << UNDERLINE << BLUE << Sarah.getName() << RESET << ":\n" << std::endl;
        std::cout << Sarah << std::endl;
    }
    catch (std::exception &e)
	{
        std::cerr << "Sarah: Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
    std::cout << "----------------------------" << std::endl;

    try
	{
        Bureaucrat Humma("Humma Kavula", 149);
        std::cout << "for " << BOLD << BLUE << UNDERLINE << BLUE << Humma.getName() << RESET << ":\n" << std::endl;
        std::cout << Humma << std::endl;
        Humma.decrementGrade();
        std::cout << Humma << std::endl;
        Humma.decrementGrade();
    }
    catch (std::exception &e)
	{
        std::cerr << "Humma: Exception: " << e.what() << std::endl;
	}
    try
	{
        Bureaucrat Sarah("Sarah Connor", 151);
        std::cout << "for " << BOLD << BLUE << UNDERLINE << BLUE << Sarah.getName() << RESET << ":\n" << std::endl;
        std::cout << Sarah << std::endl;
    }
    catch (std::exception &e)
	{
        std::cerr << "Sarah: Exception: " << e.what() << std::endl;
	}
    return 0;
}
