/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: june <june@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:14:14 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/03 12:28:08 by june             ###   ########.fr       */
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
	std::cout << "getRawBits mebmer function called" << std::endl;
	return (fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits memeber funciton called" << std::endl;
	fixedPointValue = raw;
}
