/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: june <june@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:34:45 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/21 10:48:27 by june             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

int main()
{
    Intern intern;

    AForm *form1 = intern.makeForm("ShrubberyCreationForm", "Tree");
    AForm *form2 = intern.makeForm("RobotomyRequestForm", "Bender");
    AForm *form3 = intern.makeForm("PresidentialPardonForm", "Zaphod");
    AForm *form4 = intern.makeForm("unknown form", "Nowhere");

    std::cout << "-----------" << std::endl;

    if (form1) {
        std::cout << "Created form: " << *form1 << std::endl;
    } else {
        std::cout << "Failed to create 'ShrubberyCreationForm'" <<  std::endl;
    }

    if (form2) {
        std::cout << "Created form: " << *form2 << std::endl;
    } else {
        std::cout << "Failed to create 'RobotomyRequestForm'" << std::endl;
    }

    if (form3) {
        std::cout << "Created form: " << *form3 << std::endl;
    } else {
        std::cout << "Failed to create 'PresidentialPardonForm'" << std::endl;
    }

    if (form4) {
        std::cout << "Created form: " << *form4 << std::endl;
    } else {
        std::cout << "Failed to create 'unknown form'." << std::endl;
    }

    delete form1;
    delete form2;
    delete form3;
    delete form4;

    return 0;
}
