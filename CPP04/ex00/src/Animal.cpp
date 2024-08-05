/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:23:46 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/05 09:39:03 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal created" << std::endl;
}

Animal::Animal(const Animal &copy) : _type(copy._type)
{
	std::cout << "Animal created by copy" << std::endl;
	*this = copy;
}

Animal& Animal::operator=(const Animal &copy)
{
	std::cout << "Animal copy assigned" << std::endl;
	if (this != &copy)
		_type = copy._type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructed" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal makes a sound" << std::endl;
}

std::string Animal::getType() const
{
	return _type;
}
