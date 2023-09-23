#include "PmergeMe.hpp"

int	main()
{
	string	str;
	getline(std::cin, str);
	PM merge(str);
	try
	{
		merge.checkIfYouCanStart();
		merge.printVector();
	}
	catch(const char *e)
	{
		std::cerr << e << std::endl;
	}
	return (0);
}

