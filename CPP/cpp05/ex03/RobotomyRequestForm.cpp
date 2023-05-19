#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() 
	: Form("RobotomyRequestForm", 72, 45), target("none")
{
	std::cout << "[RobotomyRequestForm] Default constructor" << '\n';
}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
	: Form("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "[RobotomyRequestForm] constructor" << '\n';
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
	: Form("RobotomyRequestForm", 72, 45), target(obj.getTarget())
{
	std::cout << "[RobotomyRequestForm] Copy constructor" << '\n';
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "[RobotomyRequestForm] Destructor" << '\n';
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) {
	this->target = obj.getTarget();
	std::cout << "[RobotomyRequestForm] Copy assignment operator" << '\n';
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if (this->getCheckSign() == true)
	{
		if (executor.getGrade() > this->getGradeExec())
			throw Form::GradeTooLowException();
		else if (executor.getGrade() < GRADE_HIGH)
			throw Form::GradeTooHighException();
		else
		{
			std::cout << "Drrrrrrrrriiiiiiiilllllllllllll" << '\n';
			if (rand() % 2)
				std::cout << this->target << " has been robotomized successfully" << '\n';
			else
				std::cout << this->target << " robotomy failed." << '\n';
		}
	}
	else
		throw std::string("Form not signed");
}

std::string RobotomyRequestForm::getTarget() const{
	return (this->target);
}