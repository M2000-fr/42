/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 06:37:46 by mechard           #+#    #+#             */
/*   Updated: 2025/03/29 06:37:46 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return std::cerr << "Error" << std::endl, 1;
	RPN rpn(argv[1]);
	int result = 0;
	if (!rpn.calculate(result))
		return std::cerr << "Error" << std::endl, 1;
	std::cout << result << std::endl;
	return 0;
}
