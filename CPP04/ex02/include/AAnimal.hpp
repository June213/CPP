/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:13:11 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/12 12:41:21 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class AAnimal
{
	protected:
		std::string _type;
	public:
		AAnimal();
		AAnimal(const AAnimal &copy);
		AAnimal& operator=(const AAnimal &copy);
		virtual ~AAnimal();
		virtual void makeSound() const = 0;
		std::string getType() const;
		
};

#endif
