#include "Intern.hpp"

Intern::Intern(){};

Intern::Intern(const Intern& obj)
{
	(void)obj;
};

Intern& Intern::operator=(const Intern& obj) 
{
	(void)obj;
	return (*this);
}

Intern::~Intern(){};

AForm* Intern::makeForm(const char *form_type, const char *target)
{
	std::string test = "";

	test.append(form_type);

	if (target == NULL || (test.compare("presidential") && test.compare("robotomy") && test.compare("shrubbery")))
	{
		std::cerr << "Intern creates fails" << std::endl;
		throw (6);
	}
	else
	{
		int a = test[0] - 112;
		std::cout << "Intern creates ";
		switch (a)
		{
			case 0:
				std::cout << "PresidentialPardonForm" << std::endl;
				return (new PresidentialPardonForm(target));
			case 2:
				std::cout << "RobotomyRequestForm" << std::endl;
				return (new RobotomyRequestForm(target));
			case 3:
				std::cout << "ShrubberyCreationForm" << std::endl;
				return (new ShrubberyCreationForm(target));
		}
	}
	return (NULL);
}
