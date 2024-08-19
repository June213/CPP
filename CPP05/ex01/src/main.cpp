/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:34:45 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/19 10:21:29 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 25);
        Form contract("Employment Contract", 45, 30);

        std::cout << contract;
        bob.signForm(contract);
        std::cout << contract;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

	std::cout << "----------" << std::endl;
	
    try {
        Bureaucrat alice("Alice", 60);
        Form nda("NDA", 55, 45);

        std::cout << nda;
        alice.signForm(nda);
        std::cout << nda;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

	std::cout << "----------" << std::endl;

    try {
        Bureaucrat charlie("Charlie", 160);
        Form permission("Permission Slip", 30, 20);
        
        std::cout << permission;
        charlie.signForm(permission);
        std::cout << permission;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

	std::cout << "----------" << std::endl;

    try {
        Form invalidForm("Invalid Form", 0, 20);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
