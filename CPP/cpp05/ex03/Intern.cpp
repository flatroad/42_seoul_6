#include "Intern.hpp"

Intern::Intern() {
	std::cout << "[Intern] Default constructor" << '\n';
}
Intern::Intern(const Intern& obj) {
	std::cout << "[Intern] Copy constructor" << '\n';
	(void)obj;
}
Intern::~Intern() {
	std::cout << "[Intern] Destructor" << '\n';
}
Intern& Intern::operator=(const Intern& obj) {
	std::cout << "[Intern] Copy assignment operator" << '\n';
	(void)obj;
	return (*this);
}

Form* Intern::newShrubberyCreationForm(const std::string& target){
	return (new ShrubberyCreationForm(target));
}

Form* Intern::newRobotomyRequestForm(const std::string& target){
	return (new RobotomyRequestForm(target));
}

Form* Intern::newPresidentialPardonForm(const std::string& target){
	return (new PresidentialPardonForm(target));
}


Form* Intern::makeForm(const std::string form_name, const std::string target_name)
{
	Form* (Intern::*ret[3])(const std::string& target)  = {
 		&Intern::newShrubberyCreationForm, 
		&Intern::newRobotomyRequestForm, 
		&Intern::newPresidentialPardonForm
	};
	std::string s[3] = {"shrubbery", "robo", "president"};
	for (int i = 0; i < 3; i++)
	{
		if (form_name == s[i])
			return (this->*(ret[i]))(target_name);
	}
	throw std::string("[Intern] Error message : form_name not found");
}