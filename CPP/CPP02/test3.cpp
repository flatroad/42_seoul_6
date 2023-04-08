#include <iostream>
#include <iomanip>

int main()
{

	 std::cout << std::setprecision(25);

	float a = 0.1f;
	float b = 0.2f;
	float c = a + b;

	std::cout << "a " << a <<std::endl;
	std::cout << "b " << b <<std::endl;
	std::cout << "c " << c <<std::endl;

	std::cout << "0.3 " << 0.3 << std::endl;
	if (c == 0.3)
	{
		printf("%d\n", 123);
	}

	return (0);
}