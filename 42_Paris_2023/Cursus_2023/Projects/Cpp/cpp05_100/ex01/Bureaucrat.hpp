/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:32:44 by mechard           #+#    #+#             */
/*   Updated: 2025/03/18 11:32:44 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

/* Codes ANSI pour la couleur du texte */
// Réinitialisation
#define RESET          "\033[0m"
#define STANDARD       "\033[0;"
#define BOLD           "\033[1;"
#define UNDERLINE      "\033[4;"
#define INVERT         "\033[7;"
#define MASKED         "\033[8;"

// Couleurs du texte
#define BLACK          "30m"
#define RED            "31m"
#define GREEN          "32m"
#define YELLOW         "33m"
#define BLUE           "34m"
#define MAGENTA        "35m"
#define CYAN           "36m"
#define WHITE          "37m"

class Form;

class Bureaucrat
{

public:
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();
    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(Form &form) const;

    class GradeTooHighException : public std::exception
	{
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
	{
    public:
        virtual const char* what() const throw();
    };

private:
    const std::string name;
    int grade;

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
