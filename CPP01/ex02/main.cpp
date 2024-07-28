/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: june <june@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:58:03 by june              #+#    #+#             */
/*   Updated: 2024/07/28 11:05:43 by june             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *ptr = &str;
    std::string &ref = str;

    std::cout << "String memory address: " << &str << std::endl;
    std::cout << "Pointer memory address: " << ptr << std::endl;
    std::cout << "Reference memory address: " << &ref << std::endl;
    std::cout << "String value: " << str << std::endl;
    std::cout << "Pointer value: " << *ptr << std::endl;
    std::cout << "Reference value: " << ref << std::endl;
    return (0);    
}