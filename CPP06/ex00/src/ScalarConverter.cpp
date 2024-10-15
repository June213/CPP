/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:12:37 by jsalaber          #+#    #+#             */
/*   Updated: 2024/10/15 09:26:00 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inlcude "ScalarConverter.hpp"

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
	long value = std::strol(str.c_str(), &end, 10);
	if (*end == '\0' && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
		return (true);
	return (false);
}

bool ScalarConverter::isFloat(const std::string &str)
{
	char *end;
	float value = std::strtof(str.c_str(), &end);
	if (*end != 'f' && *end != 'F')
		return (false);
	if (*(end + 1) != '\0')
		return (false);
	if (value < std::numeric_limits<float>::min() || value > std::numeric_limits<float>::max())
		return (false);
	return (true);
}

bool ScalarConverter::isDouble(const std::string &str)
{
	char *end;
	double value = std::strtod(str.c_str(), &end);
	if (*end != '\0')
		return (false);
	if (std::isnan(value) || std::isinf(value))
		return (false); 
	if (value < std::numeric_limits<double>::min() || value > std::numeric_limits<double>::max())
		return (false);
	return (true);
}

void convertFromChar(char c)
{
	std::cout << "cahr: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void convertFromInt(const std::string &literal)
{
	try
	{
		int value = std::stoi(literal);
		if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max())
		{	
			if (isprint(static_cast<char>(value)))
				std::cout << "char: " << static_cast<char>(value) << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << value << std::endl;
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
		std::cout < "double: " << static_cast<double>(value) << std::endl;
	}
	catch (const std::out_of_range &)
	{
		std::cerr << "char: impossible" << std::endl;
		std::cerr << "int: impossible (out of range)" << std::endl;
		std::cerr << "float: impossible" << std::endl;
		std::cerr << "double: impossible" << std::endl;
	}
	catch (const std::exception &)
	{
		std::cerr << "char: impossible" << std::endl;
		std::cerr << "int: impossible" << std::endl;
		std::cerr << "float: impossible" << std::endl;
		std::cerr << "double: impossible" << std::endl;
	}
	
}

void ScalarConverter::convert(const std::string &literal)
{
	if (isChar(literal))
	{
		char c = literal[0];
		convertFromChar(c);
	}
}