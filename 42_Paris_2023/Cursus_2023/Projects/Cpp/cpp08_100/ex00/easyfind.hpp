/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 07:11:13 by mechard           #+#    #+#             */
/*   Updated: 2025/03/27 07:11:13 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <vector>

/* Codes ANSI pour la couleur du texte */
// Réinitialisation
#define RESET          "\033[0m"

// Couleurs standards du texte
#define BLACK1          "\033[0;30m"
#define RED1            "\033[0;31m"
#define GREEN1          "\033[0;32m"
#define YELLOW1         "\033[0;33m"
#define BLUE1           "\033[0;34m"
#define MAGENTA1        "\033[0;35m"
#define CYAN1           "\033[0;36m"
#define WHITE1          "\033[0;37m"

// Couleurs en gras (couleurs claires)
#define BLACK2     "\033[1;30m"
#define RED2       "\033[1;31m"
#define GREEN2     "\033[1;32m"
#define YELLOW2    "\033[1;33m"
#define BLUE2      "\033[1;34m"
#define MAGENTA2   "\033[1;35m"
#define CYAN2      "\033[1;36m"
#define WHITE2     "\033[1;37m"

template <typename T>
typename T::iterator easyfind(T &container, int value);

#include "easyfind.tpp"

#endif
