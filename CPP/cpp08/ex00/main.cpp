#include "easyfind.hpp"
#include <vector>
#include <deque>

int main()
{
	std::vector<int> arr1;

	arr1.push_back(1);
	arr1.push_back(2);
	arr1.push_back(3);

	std::cout << *easyfind(arr1, 2) << std::endl;
	std::cout << *(++(++easyfind(arr1, 3))) << std::endl;
	std::vector<int>::iterator it = easyfind(arr1, 2);

	std::deque<int> arr2;
	arr2.push_back(1);
	arr2.push_back(2);
	arr2.push_back(3);

	std::cout << *easyfind(arr2, 2) << std::endl;
	std::cout << *(++it) << std::endl;
	
	try
	{
		std::cout << *easyfind(arr2, 4) << std::endl;
	}
	catch(const char *str)
	{
		std::cerr << str << std::endl;
	}
	

	return (0);
}