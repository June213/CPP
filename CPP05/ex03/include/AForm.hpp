/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:00:31 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/20 09:58:49 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	private:
		std::string const 	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;
	public:
		class GradeTooHighException;
		class GradeTooLowException;
		class FormNotSignedException;
		AForm ();
		AForm (const std::string &_name, int _gradeToSign, int _gradeToExecute);
		virtual ~AForm ();
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);

		std::string const &getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat &b);
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream &os, const AForm &f);

#endif