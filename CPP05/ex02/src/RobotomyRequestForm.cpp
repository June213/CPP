 

 #include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm(src), _target(src._target)
{
	*this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << "Drilling noises..." << std::endl;
	int random = rand() % 2;
	if (random == 0)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << _target << " robotomization failed." << std::endl;
}