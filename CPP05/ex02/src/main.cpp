/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: june <june@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:34:45 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/21 10:10:48 by june             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main() {
    try 
	{
        Bureaucrat highRankBureaucrat("Peter", 1);
        ShrubberyCreationForm shrubberyForm("home");
        std::cout << shrubberyForm;
        try
		{
            highRankBureaucrat.executeForm(shrubberyForm);
        }
		catch (std::exception &e)
		{
            std::cerr << e.what() << std::endl;
        }
        highRankBureaucrat.signForm(shrubberyForm);
        highRankBureaucrat.executeForm(shrubberyForm);

    }
		catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "-----------" << std::endl;
    
    try 
    {
        Bureaucrat john("John", 40);
        RobotomyRequestForm form("Target");
        std::cout << form;
        try
        {
            john.executeForm(form);
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        john.signForm(form);
        std::cout << form;
        john.executeForm(form);

    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "-----------" << std::endl;

    try 
    {
        Bureaucrat marie("Marie", 1);
        PresidentialPardonForm presidentialform("President");
        std::cout << presidentialform;
        try
        {
            marie.executeForm(presidentialform);
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        marie.signForm(presidentialform);
        std::cout << presidentialform;
        marie.executeForm(presidentialform);

    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

