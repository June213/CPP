/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:39:35 by jsalaber          #+#    #+#             */
/*   Updated: 2024/11/06 09:41:07 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Templates.hpp"
#include <iostream>

int main( void )
{
	std::cout << "----------------" << std::endl;
	int a = 2;
	int b = 3;
	std::cout << "Original a = " << a << ", Original b = " << b << std::endl;
	::swap( a, b );
	std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	std::cout << "----------------" << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "Original c = " << c << ", Original d = " << d << std::endl;
	::swap(c, d);
	std::cout << "After swap: c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	std::cout << "----------------" << std::endl;
	return 0;
}