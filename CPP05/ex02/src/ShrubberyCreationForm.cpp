/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:11:24 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/20 12:09:10 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137), _target("default"){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &_target)
	: AForm("Shrubbery Creation", 145, 137), _target(_target){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src), _target(src._target)
{
	*this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
	{
		this->_target = src._target;
		this->_tree = src._tree;
		
	}
	return (*this);
}

std::string ShrubberyCreationForm::_tree =
"    ccee88oo\n"
"  C8O8O8Q8PoOb o8oo\n"
"dOB69QO8PdUOpugoO9bD\n"
"CgggbU8OU qOp qOdoUOdcb\n"
"    6OuU  /p u gcoUodpP\n"
"      \\\\\\//  /douUP\n"
"        \\\\\\////\n"
"          |||/\\\n"
"          |||\\/\n"
"          |||||\n"
"   .....//||||\\....\n"

;

class ShrubberyCreationForm::FileErrorException : public std::exception
{
	public:
		const char* what() const throw()
		{
			return ("Error: could not open file.");
		}
};

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	try
	{
		std::ofstream file;
		std::string filename = this->_target + "_shrubbery";
		file.open(filename.c_str());
		if (file.is_open())
		{
			file << ShrubberyCreationForm::_tree;
			file.close();
		}
		else
			throw FileErrorException();
		std::cout << getName() << " has been executed by " << executor.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}
