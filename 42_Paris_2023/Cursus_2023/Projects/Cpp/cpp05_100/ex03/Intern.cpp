/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:03:00 by mechard           #+#    #+#             */
/*   Updated: 2025/03/21 13:03:00 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

typedef AForm* (*FormCreator)(const std::string &target);

static AForm *createShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

static AForm *createRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

static AForm *createPresidential(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{

    typedef struct
	{
        std::string name;
        FormCreator creator;
    } formMapping;

    formMapping mappings[3] =
	{
        {"shrubbery creation", &createShrubbery},
        {"robotomy request", &createRobotomy},
        {"presidential pardon", &createPresidential}
    };

    for (int i = 0; i < 3; i++)
	{
        if (mappings[i].name == formName)
		{
            AForm *form = mappings[i].creator(target);
            std::cout << BOLD YELLOW UNDERLINE YELLOW << "Intern" << RESET << " create " << *form << " " << UNDERLINE CYAN << formName << RESET << " form" << std::endl;
            return form;
        }
    }

    std::cout << BOLD YELLOW UNDERLINE YELLOW << "Intern" << RESET << BOLD RED << " cannot create form: " << UNDERLINE CYAN BOLD CYAN << formName << RESET << std::endl;
    return NULL;
}