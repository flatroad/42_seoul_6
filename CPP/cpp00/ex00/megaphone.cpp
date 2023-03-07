#include <iostream>
#include <string>

std::string	transToupper(char *s);

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		std::string str = transToupper(argv[i]);
		std::cout << str << " ";
	}
	std::cout << std::endl;
	return (0);
}

std::string	transToupper(char *s)
{
	std::string	str = s;
	for (int j = 0; str[j]; j++)
		str[j] = std::toupper(str[j]);
	return (str);
}
