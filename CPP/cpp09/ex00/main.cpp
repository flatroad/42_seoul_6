#include " BitcoinExchange.hpp"

void	test(int argc, char **argv);

int main(int argc, char **argv)
{
	test(argc, argv);
	system("leaks a.out");
	return (0);
}

void	test(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw ("parameter check plz");
		BERICH	calcbit(argv[1]);
		calcbit.checkOpenFile();
		calcbit.checkProperDatabase(calcbit.getDateBase());
		calcbit.checkProperInputfile(calcbit.getInputFile());
	}
	catch(const char *e)
	{
		std::cerr << e << std::endl;
	} 
}