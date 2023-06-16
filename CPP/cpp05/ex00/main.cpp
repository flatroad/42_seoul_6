#include "Bureaucrat.hpp"

void	test()
{
	Bureaucrat *test1 = NULL;
	Bureaucrat *test2 = NULL;
	try
	{
		test1 = new Bureaucrat("soun", 1);
		test2 = new Bureaucrat("choi", 1);
		try
		{
			test1->incrementGrade();
			test2->incrementGrade();
			std::cout << *test1 << std::endl;
			std::cout << *test2 << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			throw (2);
		}
		
	}
	catch(int e_num)
	{
		if (e_num == 1)
			std::cerr << "constructor fail" << std::endl;
		else if (e_num == 2)
			std::cerr << "inc or dec fail" << std::endl;
		if (test1 != NULL)
			delete test1;
		if (test2 != NULL)
			delete test2;
		return ;
		// delete test1;
		// delete test2;
	
	}
	delete test1;
	delete test2;
}

int main()
{
	test();
	system("leaks Bureaucrat");
}