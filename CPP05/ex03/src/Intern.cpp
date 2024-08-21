




#include "../include/Intern.hpp"

const std::string Intern::_formNames[3] = {
	"ShrubberyCreationForm",
	"RobotomyRequestForm",
	"PresidentialPardonForm"
};

const Intern::FormCreators Intern::_formCreators[3] = {
	&Intern::makeShrubberyCreationForm,
	&Intern::makeRobotomyRequestForm,
	&Intern::makePresidentialPardonForm
};

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern &Intern::operator=(const Intern &src)
{
	if (this == &src)
	{
		return (*this);
	}
	return (*this);
}

AForm *Intern::makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	for (int i = 0; i < 3; ++i)
	{
		if (_formNames[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*_formCreators[i])(target);
		}
	}
	std::cout << "Form not found." << std::endl;
	return (NULL);
}
