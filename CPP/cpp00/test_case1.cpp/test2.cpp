#include <iostream>
#include <string>

void	scan();

int	main()
{
	scan();
	return (0);
}

void	scan()
{
	char *kk;

	std::cin >> kk;
	std::string str = kk;

	str.append("a");

	std::cout << str << std::endl;
}