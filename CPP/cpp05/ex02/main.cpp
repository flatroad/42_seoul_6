#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
	else if (num == 9)
		std::cerr << "can't open the file" << std::endl;
}

static void	Shrubberytest()
{
	try
	{
		Bureaucrat test1("test1", 7);
		ShrubberyCreationForm form1("target1");
		try
		{
			test1.signForm(form1);
			test1.executeForm(form1);
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
	}
}

static void Robotomytest()
{
	try
	{
		Bureaucrat test2("test2", 60);
		RobotomyRequestForm form2("target2");
		try
		{
			test2.signForm(form2);
			test2.executeForm(form2);
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
	}
}

static void Presidentialtest()
{
	try
	{
		Bureaucrat test3("test3", 60);
		PresidentialPardonForm form3("target3");
		try
		{
			test3.signForm(form3);
			test3.executeForm(form3);
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
	}
}

int main()
{
	Shrubberytest();
	Robotomytest();
	Presidentialtest();
	// system("leaks Bureaucrat");
}