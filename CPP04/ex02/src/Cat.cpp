/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:43:54 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/12 12:43:43 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : AAnimal()
{
	std::cout << "Default cat created" << std::endl;
	_type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &copy) : AAnimal(copy)
{
	std::cout << "Cat created by copy" << std::endl;
	_type = copy._type;
	brain = new Brain(*copy.brain);
}
Cat& Cat::operator=(const Cat &copy)
{
	std::cout << "Cat copy assigned" << std::endl;
	if (this != &copy)
	{
		if (brain != NULL)
			delete brain;
		_type = copy._type;
		brain = new Brain(*copy.brain);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destroyed" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}

void Cat::setIdea(int i, std::string idea)
{
	brain->setIdea(i, idea);
}

std::string Cat::getIdea(int i) const
{
	return brain->getIdea(i);
}
