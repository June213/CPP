/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:27:29 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/20 12:36:45 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

class AForm::GradeTooHighException : public std::exception
{
	public:
		const char* what() const throw()
		{
			return ("Grade is too high.");
		}
};

class AForm::GradeTooLowException : public std::exception
{
	public:
		const char* what() const throw()
		{
			return ("Grade is too low.");
		}
};

class AForm::FormNotSignedException : public std::exception
{
	public:
		const char* what() const throw()
		{
			return ("Form is not signed.");
		}
};

AForm::AForm(): _name("default"), _signed(false), _gradeToSign(0), _gradeToExecute(0){}

AForm::AForm(const std::string &_name, int _gradeToSign, int _gradeToExecute):
	_name(_name), _signed(false), _gradeToSign(_gradeToSign), _gradeToExecute(_gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm(){}

AForm::AForm(const AForm &src):
	_name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	*this = src;
}

AForm &AForm::operator=(const AForm &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

std::string const &AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << f.getName() << " is ";
	if (f.getSigned())
		os << "signed" << std::endl;
	else
		os << "not signed and requires grade " << f.getGradeToSign() << " to sign and grade " << f.getGradeToExecute() << " to execute." << std::endl;
	return (os);
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!this->_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
}
