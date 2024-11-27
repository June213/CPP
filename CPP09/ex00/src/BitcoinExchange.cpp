/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:25:46 by jsalaber          #+#    #+#             */
/*   Updated: 2024/11/27 13:11:08 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string const &csvFile)
{
	loadDatabase(csvFile);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
	this->_priceHistory = src._priceHistory;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
	if (this != &src)
		this->_priceHistory = src._priceHistory;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

// c.str() -> devuelve un puntero a un array de caracteres que contiene una secuencia de caracteres con el mismo contenido que los que se encuentran en el stream

void BitcoinExchange::loadDatabase(const std::string &csvFile)
{
	std::ifstream file(csvFile.c_str());
	if (!file.is_open())
		throw std::runtime_error("Could not open csvfile");
	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string price;
		if (std::getline(ss, date, ',') && std::getline(ss, price))
			_priceHistory[date] = std::atof(price.c_str());
	}
	file.close();
}

void BitcoinExchange::processInput(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		throw std::runtime_error("Could not open file");
		return ;
	}
	file.seekg(0, std::ios::end);
	if (file.tellg() == 0)
	{
		std::cerr << "Error: Empty file" << std::endl;
		file.close();
		return ;
	}
	file.seekg(0, std::ios::beg);
	std::string line;
	if (std::getline(file, line))
	{
		if (!isdigit(line[0])) {}

		else
			analyzeInputLine(line);
	}
	while (std::getline(file, line))
		analyzeInputLine(line);
	file.close();
}

void BitcoinExchange::analyzeInputLine(const std::string &line)
{
	std::stringstream lineStream(line);
	std::string date;
	std::string value;
	if (std::getline(lineStream, date, '|') && std::getline(lineStream, value))
	{
		date = date.substr(0, date.find_last_not_of(' ') + 1);
		value = value.substr(value.find_first_not_of(' '));
		if (!isValidDate(date))
		{
			std::cerr << "Error: Invalid date => " << date << std::endl;
			return ;
		}
		if (!isValidValue(value))
		{
			std::cerr << "Error: Invalid value => " << value << std::endl;
			return ;
		}
		double val = std::atof(value.c_str());
		if (val < 0)
		{
			std::cerr << "Error: Negative value" << std::endl;
			return ;
		}
		if (val > 1000)
		{
			std::cerr << "Error: Value too high" << std::endl;
			return ;
		}
		double rate = findClosestRate(date);
		std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << val * rate << std::endl;
	}
	else
		std::cerr << "Error: Invalid input => " << line << std::endl;
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	std::string yearstr = date.substr(0, 4);
	std::string monthstr = date.substr(5, 2);
	std::string daystr = date.substr(8,2);
	int year = std::atoi(yearstr.c_str());
	int month = std::atoi(monthstr.c_str());
	int day = std::atoi(daystr.c_str());

	if (year < 2000 || year > 2024 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int maxDay = daysInMonth[month - 1];
	if (month == 2 && isLeapYear(year))
		maxDay = 29;
	return (day <= maxDay);
}

bool BitcoinExchange::isValidValue(const std::string &value) const
{
	char *end;
	std::strtod(value.c_str(), &end);
	
	if (end != value.c_str() || *end == '\0')
		return true;
	return false;
}

double BitcoinExchange::findClosestRate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = _priceHistory.lower_bound(date);
	if (it == _priceHistory.end() || it->first != date)
	{
		if (it == _priceHistory.begin())
			return 0.0;
		--it;
	}
	return (it->second);
}

bool BitcoinExchange::isLeapYear(int year)
{
	if ( year % 4 != 0)
		return false;
	if (year % 100 != 0)
		return true;
	if (year % 400 != 0)
		return true;
	return false;
}