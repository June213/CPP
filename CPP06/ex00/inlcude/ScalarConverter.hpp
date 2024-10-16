/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:12:34 by jsalaber          #+#    #+#             */
/*   Updated: 2024/10/16 09:38:32 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib> // std::strtol, std::strtof
#include <cmath> // std::issnan, std::isinf
#include <climits>
#include <cerrno>
#include <cfloat>
#include <sstream>
#include <iomanip> // Para std::setprecision

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);
		~ScalarConverter();
		static bool isChar(const std::string &str);
		static bool isInt(const std::string &str);
		static bool isFloat(const std::string &str);
		static bool isDouble(const std::string &str);
		static bool isSpecialValue(const std::string &str);
		static void convertFromChar(char c);
		static void convertFromInt(const std::string &literal);
		static void convertFromFloat(const std::string &literal);
		static void convertFromDouble(const std::string &literal);
	public:
		static void convert(const std::string &literal);
		
};

#endif