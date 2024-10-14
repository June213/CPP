/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:12:37 by jsalaber          #+#    #+#             */
/*   Updated: 2024/10/14 12:56:52 by jsalaber         ###   ########.fr       */
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