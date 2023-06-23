#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const char *target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->target_ = "";
	this->target_.append(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm("RobotomyRequestForm", 72, 45)
{
	this->target_ = obj.getTarget();
}


RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) 
{
	this->target_ = obj.getTarget();
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){};

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->get_check_sign() == false)
		throw ("[RobotomyRequestForm type] is not signed");
	if (executor.get_grade() > this->get_exec_lv())
		throw ("[RobotomyRequestForm type] is not authorized to execute");
	else
	{
		std::cout << "this is drilling noises : drill drill" << std::endl;
		std::cout << this->getTarget();
		if (rand() % 2)
			std::cout << " robotomized successfully" << std::endl;
		else
			std::cout << " robotomy failed" << std::endl;
	}
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->target_);
}
