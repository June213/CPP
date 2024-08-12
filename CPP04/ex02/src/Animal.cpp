/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:23:46 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/12 12:44:45 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << "Animal created" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) : _type(copy._type)
{
	std::cout << "Animal created by copy" << std::endl;
	*this = copy;
}

AAnimal& AAnimal::operator=(const AAnimal &copy)
{
	std::cout << "Animal copy assigned" << std::endl;
	if (this != &copy)
		_type = copy._type;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "Animal destructed" << std::endl;
}


std::string AAnimal::getType() const
{
	return _type;
}
