/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:42:25 by mechard           #+#    #+#             */
/*   Updated: 2025/03/27 08:42:25 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>

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

class Span
{

private:
	unsigned int _maxSize;
	std::vector<int> _numbers;

public:
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();
	void addNumber(int num);
	int shortestSpan() const;
	int longestSpan() const;
	template <typename Iterator>
	void addNumbers(Iterator begin, Iterator end)
	{
		for (Iterator it = begin; it != end; ++it)
		{
			if (_numbers.size() >= _maxSize)
				throw std::runtime_error("Full");
			_numbers.push_back(*it);
		}
	}

};

#endif
