/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:43:54 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/05 09:45:30 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat created by copy" << std::endl;
	*this = copy;
}
Cat& Cat::operator=(const Cat &copy)
{
	std::cout << "Cat copy assigned" << std::endl;
	if (this != &copy)
		_type = copy._type;
	return *this;
}