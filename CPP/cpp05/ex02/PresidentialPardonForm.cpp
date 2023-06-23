#include "PresidentialPardonForm.hpp"
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm(const char *target) : AForm("PresidentialPardonForm", 25, 5)
{
	this->target_ = "";
	this->target_.append(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm("PresidentialPardonForm", 25, 5)
{
	this->target_ = obj.getTarget();
}


PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) 
{
	this->target_ = obj.getTarget();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){};

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->get_check_sign() == false)
		throw ("[PresidentialPardonForm type] is not signed");
	if (executor.get_grade() > this->get_exec_lv())
		throw ("[PresidentialPardonForm type] is not authorized to execute");
	else
	{
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->target_);
}
