/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:47:50 by mechard           #+#    #+#             */
/*   Updated: 2025/03/28 16:47:50 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>

class BitcoinExchange 
{

public:
	BitcoinExchange(const std::string &dataFile);
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	bool isDatabaseLoaded() const;
	bool getExchangeRate(const std::string &date, double &rate) const;

private:
	std::map<std::string, double> _data;
	bool _loaded;
	void loadDatabase(const std::string &dataFile);

};

#endif
