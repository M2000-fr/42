/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:44:15 by mechard           #+#    #+#             */
/*   Updated: 2025/03/27 08:44:15 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	// Test 1 : Ajout simple et calcul des spans
	std::cout << "----------------Test 1----------------" << std::endl;
	std::cout << YELLOW2 << "Test 1 : Ajout simple et calcul des spans" << RESET << std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << GREEN2 << "Shortest Span: " << BLUE2 << sp.shortestSpan() << RESET << std::endl;
		std::cout << GREEN2 << "Longest Span: " << BLUE2 << sp.longestSpan() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED2 << "Erreur: " << RESET << e.what() << std::endl;
	}
		
	// Test 2 : Calcul des spans avec un seul nombre (doit lancer une exception)
	std::cout << "\n----------------Test 2----------------" << std::endl;
	std::cout << YELLOW2 << "Test 2 : Calcul des spans avec un seul nombre" << RESET << std::endl;
	try
	{
		Span sp = Span(3);
		sp.addNumber(42);
		std::cout << GREEN2 << "Shortest Span: " << BLUE2 << sp.shortestSpan() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED2 << "Exception: " << RESET << e.what() << std::endl;
	}

	// Test 3 : Tentative d'ajout en dépassant la capacité
	std::cout << "\n----------------Test 3----------------" << std::endl;
	std::cout << YELLOW2 << "Test 3 : Ajout en dépassant la capacité" << RESET << std::endl;
	try
	{
		Span sp = Span(2);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
	}
	catch (std::exception &e)
	{
		std::cout << RED2 << "Exception: " << RESET << e.what() << std::endl;
	}

	// Test 4 : Ajout d'une plage d'itérateurs avec la fonction template addNumbers
	std::cout << "\n----------------Test 4----------------" << std::endl;
	std::cout << YELLOW2 << "Test 4 : Ajout d'une plage d'itérateurs" << RESET << std::endl;
	try
	{
		Span sp = Span(10);
		std::vector<int> vec;
		vec.push_back(5);
		vec.push_back(3);
		vec.push_back(9);
		vec.push_back(1);
		sp.addNumbers(vec.begin(), vec.end());
		std::cout << GREEN2 << "Shortest Span: " << BLUE2 << sp.shortestSpan() << RESET<< std::endl;
		std::cout << GREEN2 << "Longest Span: " << BLUE2 << sp.longestSpan() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED2 << "Erreur: " << RESET << e.what() << std::endl;
	}

	// Test 5 : Calcul des spans sur un grand nombre d'éléments (10000 nombres aléatoires)
	std::cout << "\n----------------Test 5----------------" << std::endl;
	std::cout << YELLOW2 << "Test 5 : Calcul sur un grand nombre d'éléments" << RESET << std::endl;
	try
	{
		unsigned int N = 10000;
		Span sp = Span(N);
		std::vector<int> randomNumbers;
		std::srand(std::time(0));
		for (unsigned int i = 0; i < N; ++i)
			randomNumbers.push_back(std::rand());
		sp.addNumbers(randomNumbers.begin(), randomNumbers.end());
		std::cout << GREEN2 << "Shortest Span: " << BLUE2 << sp.shortestSpan() << RESET<< std::endl;
		std::cout << GREEN2 << "Longest Span: " << BLUE2 << sp.longestSpan() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED2 << "Erreur: " << RESET << e.what() << std::endl;
	}

	// Test 6 : Cas où tous les nombres sont identiques (résultats attendus : 0 pour les deux spans)
	std::cout << "\n----------------Test 6----------------" << std::endl;
	std::cout << YELLOW2 << "Test 6 : Nombres identiques" << RESET << std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(7);
		sp.addNumber(7);
		sp.addNumber(7);
		sp.addNumber(7);
		sp.addNumber(7);
		std::cout << GREEN2 << "Shortest Span: " << BLUE2 << sp.shortestSpan() << RESET<< std::endl;
		std::cout << GREEN2 << "Longest Span: " << BLUE2 << sp.longestSpan() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED2 << "Erreur: " << RESET << e.what() << std::endl;
	}

	return 0;
}
