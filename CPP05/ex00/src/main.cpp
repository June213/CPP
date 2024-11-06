/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:34:45 by jsalaber          #+#    #+#             */
/*   Updated: 2024/10/30 13:14:30 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat cd("John", 3);
		std::cout << b1 << std::endl;
		Bureaucrat b2("Jane", 149);
		std::cout << b2 << std::endl;
		b1.incrementGrade();
		b2.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "----------" << std::endl;
	try
	{
		Bureaucrat b3("Jack", 1);
		std::cout << b3 << std::endl;
		b3.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
	
}