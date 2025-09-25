/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 05:45:06 by mechard           #+#    #+#             */
/*   Updated: 2025/03/29 05:45:06 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <sstream>
#include <stack>
#include <cstdlib>
#include <iostream>
#include <cctype>

class RPN
{

public:
	RPN(const std::string &expression);
	~RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	bool calculate(int &result) const;

private:
	std::string _expression;

};

#endif
