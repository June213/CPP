/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:08:13 by jsalaber          #+#    #+#             */
/*   Updated: 2024/08/19 10:17:43 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

class Bureaucrat::GradeTooHighException : public std::exception
{
	public:
		const char *what() const throw()
		{
			return ("Grade is too high.");
		}
};

class Bureaucrat::GradeTooLowException : public std::exception
{
	public:
		const char *what() const throw()
		{
			return ("Grade is too low.");
		}
};

Bureaucrat::Bureaucrat(const std::string &_name, int _grade)
	: _name(_name), _grade(_grade)
{
		if (_grade < 1)
			throw GradeTooHighException();
		else if (_grade > 150)
			throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << " destroyed." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
	: _name(src._name), _grade(src._grade)
{
	if (_grade < 1)
			throw GradeTooHighException();
		else if (_grade > 150)
			throw GradeTooLowException();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
	{
		_grade = src._grade;
	}
	return (*this);
}

std::string const &Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
	std::cout << _name << " grade incremented to " << _grade << std::endl;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
	std::cout << _name << " grade decremented to " << _grade << std::endl;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (os);
}

void Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << _name << " signs " << f.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " could not sign " << f.getName() << " because " << e.what() << std::endl;
	}
	
}