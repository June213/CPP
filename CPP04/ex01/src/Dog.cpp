/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:34:32 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/12 11:07:25 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Default dog created" << std::endl;
	_type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog created by copy" << std::endl;
	_type = copy._type;
	brain = new Brain(*copy.brain);
	
}

Dog& Dog::operator=(const Dog &copy)
{
	std::cout << "Dog coppy assigned" << std::endl;
	if (this != &copy)
	{
		if (brain != NULL)
			delete brain;
		_type = copy._type;
		brain = new Brain (*copy.brain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructed" << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "Guau! Guau!" << std::endl;
}

void Dog::setIdea(int i, std::string idea)
{
	brain->setIdea(i, idea);
}

std::string Dog::getIdea(int i) const
{
	return brain->getIdea(i);
}
