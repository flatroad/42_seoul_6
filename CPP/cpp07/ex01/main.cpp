#include "iter.hpp"


void print_str(std::string &value)
{
	std::cout << value << std::endl;
}

void print(int& a)
{
	std::cout << a << std::endl;
}


int main()
{
	int arr[3] = {1, 2, 3};
	// double arr_d[3] = {3.1, 3.2, 4.3};
	iter(arr, 3, print);
	std::string str[3] = {"test1", "test2", "Test3"};
	iter(str, 3, print_str);
	// iter(arr, 3, print);
	// iter(arr_d, 3, print_1);
	return (0);
}