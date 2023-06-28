#include "whatever.hpp"
#include <iostream>

int main()
{
	int a = 1;
	int b = 2;
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	swap(a, b);
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "min : " << min(a, b) << std::endl;
	std::cout << "max : " << max(a, b) << std::endl;
	return (0);
}
