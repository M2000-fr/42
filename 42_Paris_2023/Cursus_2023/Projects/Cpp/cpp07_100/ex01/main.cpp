/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 05:01:14 by mechard           #+#    #+#             */
/*   Updated: 2025/08/29 13:03:12 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// ------------------
// Fonctions de test
// ------------------

void printInt(const int &elem) {
    std::cout << elem << " ";
}

void incrementInt(int &elem) {
    elem++;
}

void multiplyInt(int &elem) {
    elem *= 2;
}

void printString(const std::string &s) {
    std::cout << s << " ";
}

void toUpperCase(std::string &s) {
    for (size_t i = 0; i < s.size(); i++) {
        s[i] = std::toupper(s[i]);
    }
}

void appendSuffix(std::string &s) {
    s += "_SUFFIX";
}

// ------------------
// Fonction main
// ------------------
int main(void)
{
    size_t  size;

	// Test avec des entiers
    std::cout << BOLD YELLOW << "---------" << UNDERLINE YELLOW << "First part" << RESET << BOLD YELLOW << " : Integer---------" << RESET << std::endl;
    // Test 1 : a < b
    {
        std::cout << BOLD CYAN << "----------------Test 1----------------" << RESET << std::endl;
        int arr[] = {1, 2, 3, 4, 5};
        size = sizeof(arr) / sizeof(arr[0]);
        std::cout << "[ " << BOLD BLUE;
        iter(arr, size, printInt);
        std::cout << RESET << "]" << std::endl << std::endl;
    }
    
    // Test 2 : Incrémenter chaque entier du tableau
    {
	    std::cout << BOLD CYAN << "----------------Test 2----------------" << RESET << std::endl;
        int arr[] = {1, 5, 10, 20, 30, 40, 50};
        size = sizeof(arr) / sizeof(arr[0]);
        std::cout << BOLD GREEN << "avant :" << RESET << " [ " << BOLD BLUE;
        iter(arr, size, printInt);
	    iter(arr, size, incrementInt);
	    std::cout << RESET << "]" << std::endl << BOLD GREEN << "aprés :" << RESET << " [ " << BOLD BLUE;
	    iter(arr, size, printInt);
        std::cout << RESET << "]" << std::endl << std::endl;
    }
    
    // Test 3 : Multiplier chaque entier du tableau par 2
    {
	    std::cout << BOLD CYAN << "----------------Test 3----------------" << RESET << std::endl;
        int arr[] = {5, 7, 9, 10, 15, 699};
        size = sizeof(arr) / sizeof(arr[0]);
	    std::cout << BOLD GREEN << "avant :" << RESET << " [ " << BOLD BLUE;
        iter(arr, size, printInt);
        iter(arr, size, multiplyInt);
	    std::cout << RESET << "]" << std::endl << BOLD GREEN << "aprés :" << RESET << " [ " << BOLD BLUE;
        iter(arr, size, printInt);
        std::cout << RESET << "]" << std::endl << std::endl;
    }
    
	// Test avec des chaînes de caractères
    std::cout << BOLD YELLOW << "\n---------" << UNDERLINE YELLOW << "Second part" << RESET << BOLD YELLOW << " : String---------" << std::endl;
    
	{
        // Test 4 : Affichage d'un tableau de chaînes
	    std::cout << BOLD CYAN << "----------------Test 4----------------" << RESET << std::endl;
        std::string arr[] = {"hello", "world", "42"};
        size = sizeof(arr) / sizeof(arr[0]);
        std::cout << "[ " << BOLD BLUE;
        iter(arr, size, printString);
	    std::cout << RESET << "]" << std::endl << std::endl;
    }
    
    // Test 5 : Conversion en majuscules d'un tableau de chaînes
	{
        std::cout << BOLD CYAN << "----------------Test 5----------------" << RESET << std::endl;
        std::string arr[] = {"foo", "bar", "baz"};
        size = sizeof(arr) / sizeof(arr[0]);
        std::cout << BOLD GREEN << "avant :" << RESET << " [ " << BOLD BLUE;
        iter(arr, size, printString);
        iter(arr, size, toUpperCase);
	    std::cout << RESET << "]" << std::endl << BOLD GREEN << "aprés :" << RESET << " [ " << BOLD BLUE;
	    iter(arr, size, printString);
        std::cout << RESET << "]" << std::endl << std::endl;
    }
    
    // Test 6 : Ajout d'un suffixe à chaque chaîne du tableau
	{
        std::cout << BOLD CYAN << "----------------Test 6----------------" << RESET << std::endl;
        std::string arr[] = {"alpha", "beta", "gamma"};
        size = sizeof(arr) / sizeof(arr[0]);
        std::cout << BOLD GREEN << "avant :" << RESET << " [ " << BOLD BLUE;
        iter(arr, size, printString);
        iter(arr, size, appendSuffix);
	    std::cout << RESET << "]" << std::endl << BOLD GREEN << "aprés :" << RESET << " [ " << BOLD BLUE;
	    iter(arr, size, printString);
        std::cout << RESET << "]" << std::endl << std::endl;
    }
    
    return 0;
}