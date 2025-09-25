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

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{

public:
    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(const Bureaucrat &bureaucrat);
    
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
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
