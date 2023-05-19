#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void shrubberyTest()
{
	try
	{
		Bureaucrat bob("BOB", 4);
		Bureaucrat bob2("BOB", 138);
		ShrubberyCreationForm test1("test1");
		ShrubberyCreationForm test2("test2");
		std::cout << '\n';
		bob.signForm(test1);
		bob.executeForm(test1);
		std::cout << '\n';
		bob2.signForm(test2);
		bob2.executeForm(test2);
		std::cout << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void roboTest()
{
	try
	{
		Bureaucrat bob("BOB", 4);
		Bureaucrat bob2("BOB", 138);
		RobotomyRequestForm test1("test1");
		RobotomyRequestForm test2("test2");
		std::cout << '\n';
		bob.signForm(test1);
		bob.executeForm(test1);
		std::cout << '\n';
		bob2.signForm(test2);
		bob2.executeForm(test2);
		std::cout << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void presidentTest()
{
	try
	{
		Bureaucrat bob("BOB", 4);
		Bureaucrat bob2("BOB", 138);
		PresidentialPardonForm test1("test1");
		PresidentialPardonForm test2("test2");
		std::cout << '\n';
		bob.signForm(test1);
		bob.executeForm(test1);
		std::cout << '\n';
		bob2.signForm(test2);
		bob2.executeForm(test2);
		std::cout << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}



int main(){
	std::cout << "====== ShrubberyCreationForm Test =====" << '\n';	
	shrubberyTest();
	std::cout << '\n';
	std::cout << "====== RobotomyRequestForm Test =====" << '\n';	
	roboTest();
	std::cout << '\n';
	std::cout << "====== PresidentialPardonForm Test =====" << '\n';	
	presidentTest();
	std::cout << '\n';
}