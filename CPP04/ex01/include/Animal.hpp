/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:13:11 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/12 12:37:31 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
	protected:
		std::string _type;
		Brain 		*brain;
	public:
		Animal();
		Animal(const std::string &type);
		Animal(const Animal &copy);
		Animal& operator=(const Animal &copy);
		virtual ~Animal();
		virtual void makeSound() const;
		std::string getType() const;
		
};

#endif
