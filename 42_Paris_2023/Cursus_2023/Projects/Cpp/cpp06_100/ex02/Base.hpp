/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:36:04 by mechard           #+#    #+#             */
/*   Updated: 2025/03/27 00:36:04 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

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

class Base
{

public:
    virtual ~Base()
	{
	}

};

#endif
