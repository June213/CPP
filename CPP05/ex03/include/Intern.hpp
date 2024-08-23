/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:18:03 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/23 09:18:06 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


class Intern
{
	private:
		static const std::string _formNames[3];
		typedef AForm *(Intern::*FormCreators)(std::string target);
		static const FormCreators _formCreators[3];

	public:
		Intern();
		~Intern();
		Intern(const Intern &src);
		Intern &operator=(const Intern &src);

		AForm *makeForm(std::string formName, std::string target);
		AForm *makeShrubberyCreationForm(std::string target);
		AForm *makeRobotomyRequestForm(std::string target);
		AForm *makePresidentialPardonForm(std::string target);
};

#endif