/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:12:37 by jsalaber          #+#    #+#             */
/*   Updated: 2024/10/16 11:52:02 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string &str)
{
	if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		return (true);
	return (false);
}

bool ScalarConverter::isInt(const std::string &str)
{
	char *end;
	long value = std::strtol(str.c_str(), &end, 10);
	if (*end == '\0' && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
		return (true);
	return (false);
}

bool ScalarConverter::isFloat(const std::string &str)
{
	char *end;
	std::strtof(str.c_str(), &end);
	if (*end != 'f' && *end != 'F')
		return (false);
	if (*(end + 1) != '\0')
		return (false);
	return (true);
}

bool ScalarConverter::isDouble(const std::string &str)
{
	char *end;
	std::strtod(str.c_str(), &end);
	if (*end != '\0')
		return (false);
	return (true);
}

bool ScalarConverter::isSpecialValue(const std::string &str)
{
    if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff"
		|| str == "inf" || str == "inff")
			return (true);
	return (false);
}

void ScalarConverter::convertFromChar(char c)
{
	if (c == '\0')
		std::cout << "char: Non displayable" << std::endl;
	else if (std::isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertFromInt(const std::string &literal)
{
	char *end;
	errno = 0;
	long value = std::strtol(literal.c_str(), &end, 10);
	if (end == literal.c_str() || *end != '\0')
	{
		std::cerr << "Error: invalid input" << std::endl;
		return ;
	}
	if (errno == ERANGE || value < INT_MIN || value > INT_MAX)
	{
		std::cerr << "Error: value out of range" << std::endl;
		return ;
	}
	if (value == 0)
		std::cout << "char: Non displayable" << std::endl;
	else if (value >= CHAR_MIN && value <= CHAR_MAX && std::isprint(static_cast<char>(value)))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	if (value < -FLT_MAX || value > FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	}
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertFromFloat(const std::string &literal)
{
	char *end;
	errno = 0;
	float value = std::strtof(literal.c_str(), &end);
	if (end == literal.c_str() || (*end != 'f' && *end != '\0'))
	{
		std::cerr << "Error: invalid input" << std::endl;
		return ;
	}
	if (errno == ERANGE)
	{
		std::cerr << "Error: value out of range" << std::endl;
		return ;
	}
	if (value == 0.0f)
		std::cout << "char: Non displayable" << std::endl;
	else if (value >= CHAR_MIN && value <= CHAR_MAX && std::isprint(static_cast<char>(value)))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	if (value < INT_MIN || value > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << value << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertFromDouble(const std::string &literal)
{
	
	if (isSpecialValue(literal))
	{
        if (literal == "nan" || literal == "nanf")
		{
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
			return;
        }
		else if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
		{
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
			return;
        }
		else if (literal == "-inf" || literal == "-inff")
		{
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
			return;
        }
	}
    char *end;
    errno = 0;
    double value = std::strtod(literal.c_str(), &end);
    if (end == literal.c_str() || *end != '\0')
    {
        std::cerr << "Error: invalid input" << std::endl;
        return;
    }
    if (errno == ERANGE)
    {
        std::cerr << "Error: value out of range" << std::endl;
        return;
    }
	if (value == 0.0)
		std::cout << "char: Non displayable" << std::endl;
	else if (value >= CHAR_MIN && value <= CHAR_MAX && std::isprint(static_cast<char>(value)))
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;
    if (value < INT_MIN || value > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
    if (value < -FLT_MAX || value > FLT_MAX)
        std::cout << "float: impossible" << std::endl;
    else
	{
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	}
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: " << value << std::endl;
}


void ScalarConverter::convert(const std::string &literal)
{
	if (isSpecialValue(literal))
		convertFromDouble(literal);
	else if (isChar(literal))
	{
		char c = literal[0];
		convertFromChar(c);
	}
	else if (isInt(literal))
		convertFromInt(literal);
	else if (isFloat(literal))
		convertFromFloat(literal);
	else if (isDouble(literal))
		convertFromDouble(literal);
	else
		std::cerr << "Error: invalid input" << std::endl;
}