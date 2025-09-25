/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 07:11:07 by mechard           #+#    #+#             */
/*   Updated: 2025/03/27 07:11:07 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	// Test 1 : Recherche dans un vector, premier élément
	std::cout << "----------------Test 1----------------" << std::endl;
	std::cout << YELLOW2 << "Test 1 : Recherche dans un vector, premier élément." << RESET << std::endl << std::endl;
	{
		std::vector<int> vec;
		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);
		vec.push_back(40);
		vec.push_back(50);
		try
		{
			std::vector<int>::iterator it = easyfind(vec, 10);
			std::cout << "Élément trouvé : " << BLUE2 << *it << RESET << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception : " << RED2 << e.what() << RESET << std::endl;
		}
	}

	// Test 2 : Recherche dans un vector, élément du milieu.
	std::cout << "----------------Test 2----------------";
	std::cout << YELLOW2 << "\nTest 2 : Recherche dans un vector, élément du milieu." << RESET << std::endl << std::endl;
	{
		std::vector<int> vec;
		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);
		vec.push_back(40);
		vec.push_back(50);
		try
		{
			std::vector<int>::iterator it = easyfind(vec, 30);
			std::cout << "Élément trouvé : " << BLUE2 << *it << RESET << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception : " << RED2 << e.what() << RESET << std::endl;
		}
	}

	// Test 3 : Recherche dans un vector, dernier élément.
	std::cout << "----------------Test 3----------------";
	std::cout << YELLOW2 << "\nTest 3 : Recherche dans un vector, dernier élément." << RESET << std::endl << std::endl;
	{
		std::vector<int> vec;
		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);
		vec.push_back(40);
		vec.push_back(50);
		try
		{
			std::vector<int>::iterator it = easyfind(vec, 50);
			std::cout << "Élément trouvé : " << BLUE2 << *it << RESET << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception : " << RED2 << e.what() << RESET << std::endl;
		}
	}

	// Test 4 : Recherche dans un vector, élément absent.
	std::cout << "----------------Test 4----------------";
	std::cout << YELLOW2 << "\nTest 4 : Recherche dans un vector, élément absent." << RESET << std::endl << std::endl;
	{
		std::vector<int> vec;
		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);
		vec.push_back(40);
		vec.push_back(50);
		try
		{
			std::vector<int>::iterator it = easyfind(vec, 100);
			std::cout << "Élément trouvé : " << BLUE2 << *it << RESET << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception : " << RED2 << e.what() << RESET << std::endl;
		}
	}

	// Test 5 : Recherche dans un vector vide.
	std::cout << "----------------Test 5----------------";
	std::cout << YELLOW2 << "\nTest 5 : Recherche dans un vector vide." << RESET << std::endl << std::endl;
	{
		std::vector<int> vec;
		try
		{
			std::vector<int>::iterator it = easyfind(vec, 10);
			std::cout << "Élément trouvé : " << BLUE2 << *it << RESET << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception : " << RED2 << e.what() << RESET << std::endl;
		}
	}

	// Test 6 : Recherche dans un vector avec éléments répétés.
	std::cout << "----------------Test 6----------------";
	std::cout << YELLOW2 << "\nTest 6 : Recherche dans un vector avec éléments répétés." << RESET << std::endl << std::endl;
	{
		std::vector<int> vec;
		vec.push_back(5);
		vec.push_back(5);
		vec.push_back(10);
		vec.push_back(5);
		vec.push_back(15);
		try
		{
			std::vector<int>::iterator it = easyfind(vec, 5);
			std::cout << "Première occurrence trouvée : " << BLUE2 << *it << RESET << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception : " << RED2 << e.what() << RESET << std::endl;
		}
	}

	return 0;
}
