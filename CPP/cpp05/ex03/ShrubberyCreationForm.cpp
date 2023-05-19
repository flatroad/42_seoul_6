#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() 
	: Form("ShrubberyCreationForm", 145, 137), target("none")
{
	std::cout << "[ShrubberyCreationForm] Default constructor" << '\n';
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
	: Form("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "[ShrubberyCreationForm] constructor" << '\n';
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
	: Form("ShrubberyCreationForm", 145, 137), target(obj.getTarget())
{
	std::cout << "[ShrubberyCreationForm] Copy constructor" << '\n';
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "[ShrubberyCreationForm] Destructor" << '\n';
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) {
	this->target = obj.getTarget();
	std::cout << "[ShrubberyCreationForm] Copy assignment operator" << '\n';
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (this->getCheckSign() == true)
	{
		if (executor.getGrade() > this->getGradeExec())
			throw Form::GradeTooLowException();
		else if (executor.getGrade() < GRADE_HIGH)
			throw Form::GradeTooHighException();
		else
		{
			std::ofstream test(this->target + "_shrubbery");
			test << ASCII_TREE;
			test.close();
		}
	}
	else
		throw std::string("Form not signed");
}

std::string ShrubberyCreationForm::getTarget() const{
	return (this->target);
}