#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const char *target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target_ = "";
	this->target_.append(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target_ = obj.getTarget();
}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) 
{
	this->target_ = obj.getTarget();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){};

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->get_check_sign() == false)
		throw ("[ShrubberyCreationForm type] is not signed");
	if (executor.get_grade() > this->get_exec_lv())
		throw ("[ShrubberyCreationForm type] is not authorized to execute");
	else
	{
		std::ofstream file;
		file.open(this->target_);
		if (file.fail())
			throw (9);
		file << ASCII_TREE;
		file.close();
	}
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->target_);
}
