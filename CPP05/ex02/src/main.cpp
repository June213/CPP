/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:34:45 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/20 13:11:39 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main() {
    try 
	{
        Bureaucrat highRankBureaucrat("HighRank", 1);
        ShrubberyCreationForm shrubberyForm("home");
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

    return 0;
}

