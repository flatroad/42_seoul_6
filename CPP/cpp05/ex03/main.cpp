#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

static void e_num_catch(int num)
{
	if (num == 1)
		std::cerr << "constructor fail" << std::endl;
	else if (num == 2)
		std::cerr << "inc or dec fail" << std::endl;
	else if (num == 3)
		std::cerr << "form constructor fail" << std::endl;
	else if (num == 4)
		std::cerr << "sign error" << std::endl;
	else if (num == 5)
		std::cerr << "exec error" << std::endl;
	else if (num == 6)
		std::cerr << "intern error" << std::endl;
	else if (num == 9)
		std::cerr << "can't open the file" << std::endl;
}

static void	intern_test()
{
	Intern form1;
	AForm *test = NULL;
	try
	{
		Bureaucrat test1("test1", 7);
		try
		{
			test = form1.makeForm("robotomy", "form1");
			test1.signForm(*test);
			test1.executeForm(*test);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			throw (2);
		}
	}
	catch(int e_num)
	{
		e_num_catch(e_num);
		if (test != NULL)
			delete test;
		return ;
	}
	delete test;
}


int main()
{
	intern_test();
	system("leaks Bureaucrat");
}
