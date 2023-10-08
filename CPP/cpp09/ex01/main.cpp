#include "RPN.hpp"

void	test(int argc, char **argv);

int main(int argc, char **argv)
{
	test(argc, argv);
	system("leaks RPN");
	return (0);
}

void	test(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw ("worng param");
		RPN ipn(argv[1]);
		std::cout << ipn.calcRPN() << std::endl;
	}
	catch(const char *s)
	{
		std::cerr << s << std::endl;
	}
	catch(int a)
	{
		std::cerr << a << " div 0, is worng" << std::endl;
	}
}