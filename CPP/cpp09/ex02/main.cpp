#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
			throw ("We don't have numbers^^");
		PM merge(argc, argv);
		merge.checkIfYouCanStart();
		std::cout << "before(Vector): ";
		merge.printVector();
		std::cout << "before(List): ";
		merge.printList();
		merge.fordJohnsonVector();
	}
	catch(const char *e)
	{
		std::cerr << e << std::endl;
	}
	return (0);
}
