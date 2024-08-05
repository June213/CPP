/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:34:32 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/05 12:07:21 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Default dog created" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog created by copy" << std::endl;
	*this = copy;
}

Dog& Dog::operator=(const Dog &copy)
{
	std::cout << "Dog coppy assigned" << std::endl;
	if (this != &copy)
	{
		_type = copy._type;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructed" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Guau! Guau!" << std::endl;
}