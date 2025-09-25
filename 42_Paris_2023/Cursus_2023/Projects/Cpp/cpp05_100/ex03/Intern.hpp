/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:01:24 by mechard           #+#    #+#             */
/*   Updated: 2025/03/21 13:01:24 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

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

class Intern
{

public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();
    AForm *makeForm(const std::string &formName, const std::string &target) const;

};

#endif
