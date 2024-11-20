/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:52:45 by jsalaber          #+#    #+#             */
/*   Updated: 2024/11/20 10:18:42 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Easyfind.hpp"
#include <vector>
#include <list>

int	main()
{
	std::vector<int> v;
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
		
	try
	{
		std::vector<int>::iterator it = easyfind(v, 3);
		std::cout << "Value 1 found: " << *it << std::endl;

		it = easyfind(v, 5);
		std::cout << "Value 2 found: " << *it << std::endl;

	}
	catch (ValueNotFound &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	
	try
	{
		std::list<int>::iterator at = easyfind(lst, 20);
		std::cout << "Value list 1 found: " << *at << std::endl;
		at = easyfind(lst, 42);
		std::cout << "Value list 2 found: " << *at << std::endl;
	}

	catch (ValueNotFound &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}

