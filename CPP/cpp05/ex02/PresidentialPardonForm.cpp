#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
	: Form("PresidentialPardonForm", 25, 5), target("none")
{
	std::cout << "[PresidentialPardonForm] Default constructor" << '\n';
}
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
	: Form("PresidentialPardonForm", 25, 5), target(target)
{
	std::cout << "[PresidentialPardonForm] constructor" << '\n';
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
	: Form("PresidentialPardonForm", 25, 5), target(obj.getTarget())
{
	std::cout << "[PresidentialPardonForm] Copy constructor" << '\n';
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "[PresidentialPardonForm] Destructor" << '\n';
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
	this->target = obj.getTarget();
	std::cout << "[PresidentialPardonForm] Copy assignment operator" << '\n';
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (this->getCheckSign() == true)
	{
		if (executor.getGrade() > this->getGradeExec())
			throw Form::GradeTooLowException();
		else if (executor.getGrade() < GRADE_HIGH)
			throw Form::GradeTooHighException();
		else
		{
			std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << '\n';
		}
	}
	else
		throw std::string("Form not signed");
}

std::string PresidentialPardonForm::getTarget() const{
	return (this->target);
}