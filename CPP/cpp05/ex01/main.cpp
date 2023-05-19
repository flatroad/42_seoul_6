#include "Bureaucrat.hpp"

int main(){
	Bureaucrat BOB("BOB", 10);
	Bureaucrat AI("AI", 10);
	Form file1("file1", 10, 10);
	Form file2("file2", 1, 1);
	std::cout << '\n';
	BOB.signForm(file1);
	std::cout << '\n';
	BOB.signForm(file2);
	std::cout << '\n';
	AI.signForm(file1);
	std::cout << '\n';
}