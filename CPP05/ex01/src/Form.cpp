/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:27:29 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/19 10:04:30 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

class Form::GradeTooHighException : public std::exception
{
	public:
		const char* what() const throw()
		{
			return ("Grade is too high.");
		}
};

class Form::GradeTooLowException : public std::exception
{
	public:
		const char* what() const throw()
		{
			return ("Grade is too low.");
		}
};

Form::Form(): _name("default"), _signed(false), _gradeToSign(0), _gradeToExecute(0){}

Form::Form(const std::string &_name, int _gradeToSign, int _gradeToExecute):
	_name(_name), _signed(false), _gradeToSign(_gradeToSign), _gradeToExecute(_gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form(){}

Form::Form(const Form &src):
	_name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	*this = src;
}

Form &Form::operator=(const Form &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

std::string const &Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << "Form " << f.getName() << " is ";
	if (f.getSigned())
		os << "signed" << std::endl;
	else
		os << "not signedand requires grade " << f.getGradeToSign() << " to sign and grade " << f.getGradeToExecute() << " to execute." << std::endl;
	return (os);
}
