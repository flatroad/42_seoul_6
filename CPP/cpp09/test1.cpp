#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	std::vector<int> b;

	b = a;

	a[2] = 4;

	std::cout << a[2] << " || " << b[2] << std::endl;
}