#include <iostream>
#include <string>


int	main()
{
	char *kk;

	std::cin >> kk;
	printf("%p\n", kk);
	kk[1] = '0';

	std::cout << kk << std::endl;
	std::cin >> kk;
	std::cout << kk << std::endl;
	return (0);
}
