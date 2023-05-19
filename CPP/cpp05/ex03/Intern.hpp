#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern& obj);
		~Intern();
		Intern& operator=(const Intern& obj);
		Form* makeForm(const std::string form_name, const std::string target_name);
		Form* newShrubberyCreationForm(const std::string& target);
		Form* newRobotomyRequestForm(const std::string& target);
		Form* newPresidentialPardonForm(const std::string& target);
};

#endif