/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:57:29 by mechard           #+#    #+#             */
/*   Updated: 2025/03/18 11:57:29 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

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

class Bureaucrat;

class AForm
{

public:
    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(const Bureaucrat &bureaucrat);
    void execute(Bureaucrat const & executor) const;
    class GradeTooHighException : public std::exception {

public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

protected:
    virtual void executeAction() const = 0;

private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
