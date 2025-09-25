/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:32:40 by mechard           #+#    #+#             */
/*   Updated: 2025/03/18 11:32:40 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
	{
        this->grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return BOLD RED "Grade too high !" RESET;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return BOLD RED "Grade too low !" RESET;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << BOLD CYAN UNDERLINE CYAN << bureaucrat.getName() << RESET << ", bureaucrat grade " << BOLD CYAN UNDERLINE CYAN << bureaucrat.getGrade() << RESET << ".";
    return out;
}

void Bureaucrat::signForm(Form &form) const
{
    if (form.getIsSigned() == true)
        std::cout << BOLD BLUE << form.getName() << BOLD GREEN << " is already signed" << RESET << ", so " << BOLD CYAN UNDERLINE CYAN << getName() << RESET << BOLD RED << " couldn't sign it !" << RESET << std::endl;
    else
    {
        try
	    {
            form.beSigned(*this);
            std::cout << BOLD CYAN UNDERLINE CYAN << name << RESET << BOLD MAGENTA << " signed " << BOLD CYAN << form << RESET << std::endl;
        }
        catch (std::exception &e)
	    {
            std::cout << BOLD CYAN UNDERLINE CYAN << name << RESET << BOLD MAGENTA << " couldn't sign " << BOLD CYAN << form << RESET << " because " << e.what() << std::endl;
        }
    }
}
