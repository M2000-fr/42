/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 10:30:59 by mechard           #+#    #+#             */
/*   Updated: 2025/08/29 10:30:59 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// Struct for test "Complex Array Type from own struct"
struct s_test {
	int a;
	char b;
};

#define MAX_VAL 750
int main(int, char**)
{
	// Test avec le main.cpp fourni ! //
	std::cout << BOLD YELLOW << "--------" << UNDERLINE YELLOW << "First part" << RESET << BOLD YELLOW << " : main.cpp---------" << RESET << std::endl;
	{
		Array<int> numbers(MAX_VAL);
    	int* mirror = new int[MAX_VAL];
    	srand(time(NULL));
    	for (int i = 0; i < MAX_VAL; i++)
    	{
    	    const int value = rand();
    	    numbers[i] = value;
    	    mirror[i] = value;
    	}
    	//SCOPE
    	{
    	    Array<int> tmp = numbers;
    	    Array<int> test(tmp);
    	}

    	for (int i = 0; i < MAX_VAL; i++)
    	{
    	    if (mirror[i] != numbers[i])
    	    {
    	        std::cerr << "didn't save the same value!!" << std::endl;
    	        return 1;
    	    }
    	}
    	try
    	{
    	    numbers[-2] = 0;
    	}
    	catch(const std::exception& e)
    	{
    	    std::cerr << e.what() << '\n';
    	}
    	try
    	{
    	    numbers[MAX_VAL] = 0;
    	}
    	catch(const std::exception& e)
    	{
    	    std::cerr << e.what() << '\n';
    	}

    	for (int i = 0; i < MAX_VAL; i++)
    	{
    	    numbers[i] = rand();
    	}
    	delete [] mirror;//
	}

	// Test avec des chaînes de caractères
    std::cout << BOLD YELLOW << "\n----------" << UNDERLINE YELLOW << "Second part" << RESET << BOLD YELLOW << " : Perso---------" << std::endl;

	Array<int> emptyArray;
	int i = -1;
	
	Array<int> intArray(5);
	while (++i < 5)
		intArray[i] = i;

	Array<int> intArrayCopy(intArray);

	Array<double> doubleArray(10);
	i = -1;
    while (++i < 10)
		doubleArray[i] = i / 2.0;
	

	{
		std::cout << BOLD CYAN << "--------Test 1 - Empty array----------" << RESET << std::endl;
		std::cout << BOLD BLUE UNDERLINE BLUE << "emptyArray size" << RESET << ": " << BOLD GREEN << emptyArray.size() << RESET << std::endl;
	}
	
	{
		std::cout << BOLD CYAN << "-------Test 2 - Out of Bounds---------" << RESET << std::endl;
		try {
			std::cout <<  BOLD BLUE UNDERLINE BLUE << "emptyArray[5]" << RESET << ": " << BOLD GREEN << emptyArray[5] << RESET << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << BOLD CYAN << "---------Test 3 - Int Array-----------" << RESET << std::endl;
		std::cout << BOLD BLUE UNDERLINE BLUE << "intArray size" << RESET << ": " << BOLD GREEN << intArray.size() << RESET << std::endl;
		std::cout << BOLD BLUE UNDERLINE BLUE << "intArray" << RESET << ": " << BOLD GREEN;
		i = 0;
		while (i < 5) {
			std::cout << intArray[i] << " ";
			i++;
		}
		std::cout << RESET << std::endl;
	}

	{
		std::cout << BOLD CYAN << "---------Test 4 - Dbl Array-----------" << RESET << std::endl;
		std::cout << BOLD BLUE UNDERLINE BLUE << "doubleArray size" << RESET << ": " << BOLD GREEN << doubleArray.size() << std::endl;
		std::cout << BOLD BLUE UNDERLINE BLUE << "doubleArray" << RESET << ": " << BOLD GREEN;
		i = 0;
		while (i < 10) {
			std::cout << doubleArray[i] << " ";
			i++;
		}
		std::cout << std::endl;
	}

	{
		std::cout << BOLD CYAN << "---------Test 5 - Copy test-----------" << RESET << std::endl;
    	std::cout << BOLD BLUE UNDERLINE BLUE << "intArrayCopy size" << RESET << ": " << BOLD GREEN << intArrayCopy.size() << std::endl;
    	std::cout << BOLD BLUE UNDERLINE BLUE << "intArrayCopy" << RESET << ": " << BOLD GREEN;
    	i = 0;
    	while (i < 5) {
    	    std::cout << intArrayCopy[i] << " ";
    	    i++;
    	}
    	std::cout << std::endl;
	}

	{
		std::cout << BOLD CYAN << "--------Test 6 - Op. dbl test---------" << RESET << std::endl;
    	Array<double> doubleArrayAssignment = doubleArray;
    	std::cout << BOLD BLUE UNDERLINE BLUE << "doubleArrayAssignment size" << RESET << ": " << BOLD GREEN << doubleArrayAssignment.size() << std::endl;
    	std::cout << BOLD BLUE UNDERLINE BLUE << "doubleArrayAssignment" << RESET << ": " << BOLD GREEN;
    	i = 0;
    	while (i < 10) {
    	    std::cout << doubleArrayAssignment[i] << " ";
    	    i++;
    	}
    	std::cout << std::endl;
	}

	{
		std::cout << BOLD CYAN << "-------Test 7- Const Variable--------" << RESET << std::endl;
		const Array<int> constIntArray(intArray);
		std::cout << BOLD BLUE UNDERLINE BLUE << "constIntArray size" << RESET << ": " << BOLD GREEN << constIntArray.size() << std::endl;
		std::cout << BOLD BLUE UNDERLINE BLUE << "constIntArray" << RESET << ": " << BOLD GREEN;
		i = 0;
		while (i < 5) {
			std::cout << constIntArray[i] << " ";
			i++;
		}
		std::cout << std::endl;
	}

	{
		std::cout << BOLD CYAN << "--------Test 8 - Complex Array--------" << RESET << std::endl;
		Array<s_test> structArray(6);
		i = 0;
		while (i < 6) {
			structArray[i].a = i;
			structArray[i].b = 'a' + i;
			i++;
		}
		std::cout << BOLD BLUE UNDERLINE BLUE << "structArray size" << RESET << ": " << BOLD GREEN << structArray.size() << std::endl;
		std::cout << BOLD BLUE UNDERLINE BLUE << "structArray" << RESET << ": " << BOLD GREEN;
		i = 0;
		while (i < 6) {
			std::cout << structArray[i].a << structArray[i].b << " ";
			i++;
		}
		Array<std::string> s(3);           // doit créer 3 strings vides
    	s[0] = "hello"; s[1] = "42"; s[2] = "Paris";
    	Array<std::string> t = s;          // deep copy
		std::cout << BOLD BLUE UNDERLINE BLUE << "\ns size" << RESET << ": " << BOLD GREEN << s.size() << BOLD BLUE UNDERLINE BLUE << "\nt size" << RESET << ": " << BOLD GREEN << t.size() << RESET << std::endl << std::endl;
		std::cout << BOLD BLUE UNDERLINE BLUE << "s before: " << RESET << ": " << BOLD GREEN;
		i = 0;
		while (i < 3) {
			std::cout << s[i] << " ";
			i++;
		}
		std::cout << BOLD BLUE UNDERLINE BLUE << "t before: " << RESET << ": " << BOLD GREEN;
		i = 0;
		while (i < 3) {
			std::cout << t[i] << " ";
			i++;
		}
    	s[1] = "school";
		std::cout << std::endl;
		std::cout << BOLD BLUE UNDERLINE BLUE << "s after: " << RESET << ": " << BOLD GREEN;
		i = 0;
		while (i < 3) {
			std::cout << s[i] << " ";
			i++;
		}
		std::cout << BOLD BLUE UNDERLINE BLUE << "t after: " << RESET << ": " << BOLD GREEN;
		i = 0;
		while (i < 3) {
			std::cout << t[i] << " ";
			i++;
		}
		std::cout << std::endl;
	}

	return (0);
}