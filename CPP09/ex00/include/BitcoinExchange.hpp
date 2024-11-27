/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:44:02 by jsalaber          #+#    #+#             */
/*   Updated: 2024/11/27 12:30:49 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream> //ifstream (lectura) ofstream (escritura) fstream (ambas)
#include <sstream> // convertir, dividir o concatenar strings
#include <iomanip> //manipular ssalida de datos setprecision
#include <cstdlib> // conversion de numeros strtos atoi
#include <exception>
#include <limits>
#include <cctype> // isdigit

class BitcoinExchange
{
	private:
		std::map<std::string, double> _priceHistory;
		void loadDatabase(const std::string &csvFile);
		void analyzeInputLine(const std::string &line);
		bool isValidDate(const std::string &date) const;
		bool isValidValue(const std::string &value) const;
		double findClosestRate(const std::string &date) const;
		static bool isLeapYear(int year);

	public:
		BitcoinExchange();
		BitcoinExchange(std::string const &csvFile);
		BitcoinExchange(BitcoinExchange const & src);
		BitcoinExchange &operator=(BitcoinExchange const &src);
		~BitcoinExchange();
		void processInput(const std::string &filename);
};

#endif