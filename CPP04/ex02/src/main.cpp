/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:39:29 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/12 12:44:58 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AAnimal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include "../include/Brain.hpp"

int main()
{
    Dog dog1;
    Cat cat1;

	Dog dog2(dog1);
	Cat cat2(cat1);
	std::cout << "-----" << std::endl;
    dog1.setIdea(8, "Fetch the ball");
    cat1.setIdea(0, "Climb the tree");

	for (int i = 0; i < 10; ++i)
		std::cout << "Dog1 idea " << i << ": " << dog1.getIdea(i) << std::endl;
    
	std::cout << "-----" << std::endl;
    std::cout << "Cat1 idea 0: " << cat1.getIdea(0) << std::endl;
    std::cout << "Cat2 idea 0: " << cat2.getIdea(0) << std::endl;

	std::cout << "-----" << std::endl;
	std::cout << "Dog1 makes sound: ";
    dog1.makeSound();
	std::cout << "Cat1 makes sound: ";
    cat1.makeSound();

	std::cout << "Dog2 makes sound: ";
    dog2.makeSound();
	std::cout << "Cat2 makes sound: ";
    cat2.makeSound();
	std::cout << "-----" << std::endl;
    return 0;
}


