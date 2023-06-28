#include "MutantStack.hpp"
#include <list>

static void test2()
{
	MutantStack<int> a;
	MutantStack<int> c;
	std::list<int> b;
	a.push(2);
	c = a;
	std::cout << c.top() << std::endl;
	a.push(3);
	std::cout << c.top() << std::endl;
	a.push(4);
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	std::cout << "a 의 top : " << a.top() << std::endl;
	std::cout << "a 의 begin : " << *(a.begin()) << std::endl;
	std::cout << "a 의 end : " << *(a.end() - 1) << std::endl;
	std::cout << "a 의 rend : " << *(a.rend() - 1) << std::endl;
	std::cout << "a 의 rbegin : " << *(a.rbegin()) << std::endl;

	std::deque<int>::iterator it_s= a.begin();
	for (; it_s != a.end(); it_s++)
	{
		std::cout << (*it_s) << " ";
	}
	std::cout << std::endl;
	std::list<int>::iterator it_l = b.begin();
	for (; it_l != b.end(); it_l++)
	{
		std::cout << (*it_l) << " ";
	}
	std::cout << std::endl;
}

static int test1()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

static void test3()
{
	std::stack<int> a;
	std::stack<int> b;
	a.push(1);
	b = a;
	std::cout << a.top() << std::endl;
	std::cout << b.top() << std::endl;
	b.push(2);
	std::cout << a.top() << std::endl;
	std::cout << b.top() << std::endl;
	b.pop();
	std::cout << a.top() << std::endl;
	std::cout << b.top() << std::endl;
}

int main()
{
	test1();
	test2();
	test3();
	system("leaks MutantStack");
	return (0);
}