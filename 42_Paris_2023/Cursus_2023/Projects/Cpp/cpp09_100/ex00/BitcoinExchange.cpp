/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:47:47 by mechard           #+#    #+#             */
/*   Updated: 2025/03/28 16:47:47 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &dataFile) : _loaded(false)
{
	loadDatabase(dataFile);
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	(void)other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	(void)other;
	return *this;
}

bool BitcoinExchange::isDatabaseLoaded() const 
{
	return _loaded;
}

void BitcoinExchange::loadDatabase(const std::string &dataFile) 
{
	std::ifstream infile(dataFile.c_str());
	if (!infile)
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return;
	}
	std::string line;
	if (std::getline(infile, line))
	{
		if (line.find("date") == std::string::npos)
		{
			std::istringstream iss(line);
			std::string date;
			std::string rateStr;
			if (std::getline(iss, date, ',') && std::getline(iss, rateStr))
			{
				size_t start = date.find_first_not_of(" \t");
				size_t end = date.find_last_not_of(" \t");
				if (start != std::string::npos && end != std::string::npos)
					date = date.substr(start, end - start + 1);
				start = rateStr.find_first_not_of(" \t");
				end = rateStr.find_last_not_of(" \t");
				if (start != std::string::npos && end != std::string::npos)
					rateStr = rateStr.substr(start, end - start + 1);
				double rate = atof(rateStr.c_str());
				_data[date] = rate;
			}
		}
	}
	while (std::getline(infile, line))
	{
		if (line.empty())
			continue;
		std::istringstream iss(line);
		std::string date;
		std::string rateStr;
		if (std::getline(iss, date, ',') && std::getline(iss, rateStr))
		{
			size_t start = date.find_first_not_of(" \t");
			size_t end = date.find_last_not_of(" \t");
			if (start != std::string::npos && end != std::string::npos)
				date = date.substr(start, end - start + 1);
			start = rateStr.find_first_not_of(" \t");
			end = rateStr.find_last_not_of(" \t");
			if (start != std::string::npos && end != std::string::npos)
				rateStr = rateStr.substr(start, end - start + 1);
			double rate = atof(rateStr.c_str());
			_data[date] = rate;
		}
	}
	_loaded = !_data.empty();
}

bool BitcoinExchange::getExchangeRate(const std::string &date, double &rate) const {
	if (_data.empty())
		return false;
	std::map<std::string, double>::const_iterator it = _data.find(date);
	if (it != _data.end())
		return rate = it->second, true;
	else
	{
		it = _data.upper_bound(date);
		if (it == _data.begin())
			return false;
		--it;
		rate = it->second;
		return true;
	}
}
