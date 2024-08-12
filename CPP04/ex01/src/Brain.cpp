/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:02:13 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/12 11:02:04 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
	{
		ideas[i] = src.ideas[i];
	}
}

Brain& Brain::operator=(const Brain &src)
{
	std::cout << "Brain copy assigned" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; ++i)
			ideas[i] = src.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructed" << std::endl;
}

void Brain::setIdea(int i, std::string idea)
{
	ideas[i] = idea;
}

std::string Brain::getIdea(int i) const
{
	return ideas[i];
}