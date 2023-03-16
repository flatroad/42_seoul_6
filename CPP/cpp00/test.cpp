#include <iostream>
#include <string>

int	main()
{
	std::string	str;

	str = "123456789";

	std::string sub;

	sub = str.substr(1, 510);

	std::cout << sub << std::endl;

	return (0);
}