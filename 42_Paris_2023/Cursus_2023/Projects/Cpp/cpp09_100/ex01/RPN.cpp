/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 07:12:45 by mechard           #+#    #+#             */
/*   Updated: 2025/03/29 07:12:45 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const std::string &expression) : _expression(expression)
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return *this;
}

bool RPN::calculate(int &result) const
{
	std::istringstream iss(_expression);
	std::stack<int> stk;
	std::string token;
	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (stk.size() < 2)
				return false;
			int right = stk.top();
			stk.pop();
			int left = stk.top();
			stk.pop();
			int res = 0;
			if (token == "+")
				res = left + right;
			else if (token == "-")
				res = left - right;
			else if (token == "*")
				res = left * right;
			else if (token == "/")
			{
				if (right == 0)
					return false;
				res = left / right;
			}
			stk.push(res);
		}
		else
		{
			for (size_t i = 0; i < token.size(); ++i)
				if (!std::isdigit(token[i]))
					return false;
			int num = std::atoi(token.c_str());
			stk.push(num);
		}
	}
	if (stk.size() != 1)
		return false;
	result = stk.top();
	return true;
}
