#include "PmergeMe.hpp"

void	test(int argc, char **argv);

int	main(int argc, char **argv)
{
	test(argc, argv);
	system("leaks a.out");
	return (0);
}

void	test(int argc, char **argv)
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
		std::cout << "Vector Time to process a range of " << merge.getCount() << " elements with std::[..] : ";
		merge.fordJohnsonVector();
		std::cout << "List Time to process a range of " << merge.getCount() << " elements with std::[..] : ";
		merge.fordJohnsonList();
		std::cout << "after(Vector): ";
		merge.printVector();
		std::cout << "after(List): ";
		merge.printList();
	}
	catch(const char *e)
	{
		std::cerr << e << std::endl;
	}
}