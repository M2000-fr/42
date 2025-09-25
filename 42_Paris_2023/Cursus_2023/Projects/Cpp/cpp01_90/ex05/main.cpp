/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 08:52:30 by mechard           #+#    #+#             */
/*   Updated: 2025/03/16 08:52:30 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

bool isKnownLevel(const std::string &level)
{
    return (level == "DEBUG" || level == "INFO" || level == "WARNING" || level == "ERROR");
}

int main(int ac, char **av)
{
    Harl harl;


	if (ac == 1)
	{
		std::cout << std::endl;
  		harl.complain("DEBUG");

		std::cout << std::endl;
    	harl.complain("INFO");

		std::cout << std::endl;
    	harl.complain("WARNING");

		std::cout << std::endl;
    	harl.complain("ERROR");

		std::cout << std::endl;
		std::cout << "[ UNKNOWN ]" << std::endl;
    	harl.complain("UNKNOWN");

		std::cout << std::endl;
		std::cout << "[ WHATEVERYOUWANT ]" << std::endl;
    	harl.complain("WHATEVERYOUWANT");
    }
	else if (ac == 2)
    {
        std::string level(av[1]);
        for (std::string::size_type i = 0; i < level.length(); ++i)
            level[i] = std::toupper(level[i]);
        std::cout << std::endl;
        if (!isKnownLevel(level))
            std::cout << "[ " << level << " ]" << std::endl;
        harl.complain(level);
        std::cout << std::endl;
    }
    else
    {
        std::cerr << "Usage: " << av[0] << " [LEVEL]" << std::endl;
    }

    return 0;
}
