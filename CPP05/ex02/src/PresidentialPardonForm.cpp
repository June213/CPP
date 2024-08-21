


#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	: AForm(src), _target(src._target)
{
	*this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
	{
		this->_target = src._target;
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
