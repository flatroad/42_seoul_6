#include <iostream>
#include <string>


int	main()
{
	std::cin >> kk;
	printf("%p\n", kk);
	kk[1] = '0';
	printf("%p\n", kk);

	std::cout << kk << std::endl;
	char *jj;
	std::cin >> jj;
	std::cout << jj << std::endl;
	return (0);
}
