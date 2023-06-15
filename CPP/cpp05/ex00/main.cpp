#include "Bureaucrat.hpp"

void	test()
{
	Bureaucrat *test1 = NULL;
	Bureaucrat *test2 = NULL;
	try
	{
		test1 = new Bureaucrat("soun", -1);
		test2 = new Bureaucrat("choi", -1);
	}
	catch(int e_num)
	{
		if (e_num == 1)
		{
			std::cerr << "constructor fail" << std::endl;
			delete test1;
			delete test2;
		}
		else if (e_num == 2)
		{
			std::cerr << "inc or dec fail" << std::endl;
			delete test1;
			delete test2;
		}
	}
}

int main()
{
	test();
	system("leaks Bureaucrat");
}