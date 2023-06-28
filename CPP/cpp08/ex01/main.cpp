#include "Span.hpp"

static void test1()
{
	Span a(8);
	Span b(8);

	try
	{
		a.addNumber(0);
		b = a;
		b.addNumber(1);
		b.addNumber(2);
		b.addNumber(3);
		b.addNumber(4);
		b.addNumber(5);
		b.addNumber(6);
		b.addNumber(7);
	}
	catch(const char *str)
	{
		std::cout << str << std::endl;
	}
	try
	{
		std::cout << b.longestSpan() << std::endl;
		std::cout << b.shortestSpan() << std::endl;
		std::cout << a.longestSpan() << std::endl;
		std::cout << a.shortestSpan() << std::endl;
	}
	catch(const char *str)
	{
		std::cout << str << std::endl;
	}
}

static void test2()
{
	Span a(100);
	try
	{
		a.fill_arr(100);
		std::cout << a.longestSpan() << std::endl;
		std::cout << a.shortestSpan() << std::endl;
		a.addNumber(0);
	}
	catch(const char *str)
	{
		std::cout << str << std::endl;
	}
}

static void test3()
{
	std::vector<int> arr1;
	std::vector<int> arr2;
	arr1.push_back(1);
	arr1.push_back(2);
	arr1.push_back(3);
	std::cout << arr1.size() << std::endl;

	std::cout << &arr1 << std::endl;
	std::cout << &arr2 << std::endl;
	arr2 = arr1;
	std::cout << &arr1 << std::endl;
	std::cout << &arr2 << std::endl;
	arr1[0] = 3;
	std::cout << arr1[0] << std::endl;
	std::cout << arr2[0] << std::endl;
}

int main()
{
	std::cout << "test1" << std::endl;
	test1();
	std::cout << "test2" << std::endl;
	test2();
	std::cout << "test3" << std::endl;
	test3();
	system("leaks Span");
}