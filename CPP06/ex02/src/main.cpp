/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:53:38 by jsalaber          #+#    #+#             */
/*   Updated: 2024/10/22 10:12:45 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include <cstdlib> //rand()
#include <ctime> //time()

Base *generate(void)
{
	Base* base = NULL;
	int random = std::rand();
	std::cout << "Random number: " << random << std::endl;

	if (random % 3 == 0)
	{
		base = new A();
		std::cout << "A created\n";
	}
	else if (random % 3 == 1)
	{
		base = new B();
		std::cout << "B created\n";
	}
	else
	{
		base = new C();
		std::cout << "C created\n";
	}
	return base;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Belongs to class A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Belongs to class B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Belongs to class C" << std::endl;
	else
		std::cout << "Unknown class" << std::endl;
}

void identify(Base& p)
{
	identify(&p);
}


int main()
{
	std::srand(std::time(0));
	Base* base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}