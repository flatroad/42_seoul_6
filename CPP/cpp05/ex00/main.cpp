#include "Bureaucrat.hpp"

int main(){
	try
	{
		Bureaucrat *test1 = new Bureaucrat("soun", 3);
		Bureaucrat *test2 = new Bureaucrat("choi", 2);
	}
	catch(int e_num)
	{
		if (e_num == 1)
		{
			std::cerr << "constructor fail" << std::endl;
			delete test1;
			delete test2;
		}
		else if (int e_num == 2)
		{
			std::cerr << "inc or dec fail" << std::endl;
			delete test1;
			delete test2;
		}
	}
}