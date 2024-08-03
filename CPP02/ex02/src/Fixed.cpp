/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: june <june@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:14:14 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/03 13:22:54 by june             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) : fixedPointValue(src.fixedPointValue)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	fixedPointValue = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	fixedPointValue = roundf(value * (1 << fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		fixedPointValue = src.fixedPointValue;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void)const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits memeber funciton called" << std::endl;
	fixedPointValue = raw;
}

int Fixed::toInt(void)const
{
	return (fixedPointValue >> fractionalBits);
}

float Fixed::toFloat(void)const
{
	return ((float)fixedPointValue / (1 << fractionalBits));
}

std::ostream& operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return out;
}

bool Fixed::operator<(const Fixed &src) const
{
	if (fixedPointValue > src.fixedPointValue)
		return (false);
	return (true);
}

bool Fixed::operator>(const Fixed &src) const
{
	if (fixedPointValue < src.fixedPointValue)
		return (false);
	return (true);
}

bool Fixed::operator<=(const Fixed &src) const
{
	if (fixedPointValue > src.fixedPointValue)
		return (false);
	return (true);
}

bool Fixed::operator>=(const Fixed &src) const
{
	if (fixedPointValue < src.fixedPointValue)
		return (false);
	return (true);
}

bool Fixed::operator==(const Fixed &src) const
{
	if (fixedPointValue != src.fixedPointValue)
		return (false);
	return (true);
}

bool Fixed::operator!=(const Fixed &src) const
{
	if (fixedPointValue == src.fixedPointValue)
		return (false);
	return (true);
}

Fixed Fixed::operator+(const Fixed &src) const
{
	Fixed result;
	
	result.setRawBits(fixedPointValue + src.fixedPointValue);
	return result;
}

Fixed Fixed::operator-(const Fixed &src) const
{
	Fixed result;
	
	result.setRawBits(fixedPointValue - src.fixedPointValue);
	return result;
}

Fixed Fixed::operator*(const Fixed &src) const
{
	Fixed result;
	
	result.setRawBits((fixedPointValue * src.fixedPointValue) >> fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed &src) const
{
	Fixed result;
	
	result.setRawBits((fixedPointValue << fractionalBits) / src.fixedPointValue);
	return result;
}

Fixed &Fixed::operator++(void)
{
	fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--(void)
{
	fixedPointValue--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return a;
	return b;
}

Fixed const &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a <= b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return a;
	return b;
}

Fixed const &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a >= b)
		return a;
	return b;
}
