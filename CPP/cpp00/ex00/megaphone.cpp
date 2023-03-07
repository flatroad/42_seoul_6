#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		std::string str = argv[i];
		for (int j = 0; str[j]; j++)
			str[j] = std::toupper(str[j]);
		std::cout << str << " ";
	}
	std::cout << std::endl;
	return (0);
}
