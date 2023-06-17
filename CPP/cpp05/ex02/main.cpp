#include "Bureaucrat.hpp"
#include "Form.hpp"

void	test()
{
	Bureaucrat *test1 = NULL;
	Form *payment_documents = NULL;
	try
	{
		test1 = new Bureaucrat("soun", 7);
		payment_documents = new Form("docu", 5, 3);
		try
		{
			std::cout << *test1 << std::endl;
			std::cout << *payment_documents << std::endl;
			test1->grade_increment();
			test1->signForm(*payment_documents);
			std::cout << *test1 << std::endl;
			std::cout << *payment_documents << std::endl;
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
		else if (e_num == 3)
			std::cerr << "form constructor fail" << std::endl;
		else if (e_num == 4)
			std::cerr << "sign error" << std::endl;
		if (test1 != NULL)
			delete test1;
		if (payment_documents != NULL)
			delete payment_documents;
		return ;
		// delete test1;
		// delete payment_documents;
	
	}
	delete test1;
	delete payment_documents;
}

int main()
{
	test();
	system("leaks Bureaucrat");
}