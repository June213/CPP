/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:48:23 by jsalaber          #+#    #+#             */
/*   Updated: 2024/11/20 12:28:44 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

int main()
{
	Span sp = Span(10);
	std::cout << "Empty span created." << std::endl;
	try
	{
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(4);
		sp.addNumber(6);
		sp.addNumber(8);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "-----------------" << std::endl;
	
	Span sp1 = sp;
	std::cout << "Span copied." << std::endl;
	try
	{
		std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp1.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "-----------------" << std::endl;
	try
	{
		Span spFull = Span(4);
		std::cout << "Full span created." << std::endl;
		spFull.addNumber(1);
		spFull.addNumber(2);
		spFull.addNumber(3);
		spFull.addNumber(4);
		spFull.addNumber(5);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "-----------------" << std::endl;
	try
	{
		Span spRange = Span(10);
		std::cout << "Vector range added." << std::endl;
		std::vector<int> range;
		for (int i = 0; i < 10; i++)
			range.push_back(i);
		spRange.addNumberRange(range.begin(), range.end());
		std::cout << "Shortest span: " << spRange.shortestSpan() << std::endl;
		std::cout << "Longest span: " << spRange.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "-----------------" << std::endl;
	
	Span sprandom = Span(10);
	std::cout << "Random span created." << std::endl;
	try
	{
		std::vector<int> randv;
		srand(time(0));
		for (int i = 0; i < 10; i++)
			randv.push_back(rand() % 100 + 1);
		sprandom.addNumberRange(randv.begin(), randv.end());
		std::cout << "Random vector: ";
		for (size_t i = 0; i < randv.size(); i++)
			std::cout << randv[i] << " ";
		std::cout << std::endl;
		std::cout << "Shortest span: " << sprandom.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sprandom.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}