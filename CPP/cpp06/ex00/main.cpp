#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cerr << "parameter is not correct" << std::endl;
	ScalarConverter converter(argv[1]);
	try
	{
		converter.check_type();
		converter.print_ScalarConvert();
	}
	catch (const char *err)
	{
		std::cerr << err << std::endl;
		return (1);
	}
	return (0);
}
