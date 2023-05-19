#include "Bureaucrat.hpp"

void state_print(Bureaucrat& one, Bureaucrat& two){
	std::cout << "================" << '\n';
	std::cout << one;
	std::cout << two;
	std::cout << "================" << '\n';
}

int main(){
	Bureaucrat one("one", 150);
	Bureaucrat two("two", 1);
	try
	{
		one.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		two.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	state_print(one, two);
	std::cout << "===== 증감 ======" << '\n';
	one.decrementGrade();
	two.incrementGrade();
	state_print(one, two);
}