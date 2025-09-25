/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:57:26 by mechard           #+#    #+#             */
/*   Updated: 2025/03/18 11:57:26 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
	{
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

AForm::~AForm()
{}

std::string AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= gradeToSign)
        isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!isSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw AForm::GradeTooLowException();
    executeAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return BOLD RED "AForm: Grade too high!" RESET;
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return BOLD RED "AForm: Grade too low!" RESET;
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return BOLD RED "AForm: Form not signed!" RESET;
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << BOLD BLUE << form.getName() << RESET
        << " [signed: " << (form.getIsSigned() ? BOLD GREEN "yes" RESET : BOLD RED "no" RESET )
        << ", grade required to sign: " << BOLD YELLOW << form.getGradeToSign() << RESET
        << ", grade required to execute: " << BOLD YELLOW << form.getGradeToExecute() << RESET << "]";
    return out;
}
