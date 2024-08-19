/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:00:31 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/19 10:16:42 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	private:
		std::string const 	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;
	public:
		class GradeTooHighException;
		class GradeTooLowException;
		Form ();
		Form (const std::string &_name, int _gradeToSign, int _gradeToExecute);
		~Form ();
		Form(const Form &src);
		Form &operator=(const Form &src);

		std::string const &getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat &b);
};

std::ostream& operator<<(std::ostream &os, const Form &f);

#endif