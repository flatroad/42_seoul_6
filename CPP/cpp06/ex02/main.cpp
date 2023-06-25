#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>

static Base * generate(void)
{
	int cas = rand() % 3;
	switch(cas)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return (NULL);
}

static void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "is imposible" << std::endl;
}

static void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
				std::cerr << "is imposible" << std::endl;
			}
		}
	}
}

static void test()
{
	for (int i = 0; i < 5; i++)
	{
		Base *base = generate();
		std::cout << "downcast : " << std::endl;
		identify(base);
		std::cout << "upcast : " << std::endl;
		identify(*base);
		delete (base);
	}
}
int main()
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	test();
	system("leaks base");
	return (0);
}

