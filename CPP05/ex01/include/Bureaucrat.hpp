/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:48:08 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/19 10:15:21 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;
class Bureaucrat
{
	private:
		std::string const	_name;
		int 				_grade;
	public:
		Bureaucrat(const std::string &_name, int _grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &src);
		
		std::string const &getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		class GradeTooHighException;
		class GradeTooLowException; 
		void signForm(Form &f);
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b);

#endif