#include <iostream>
#include <string> 


namespace ProgcomImp1
{
	void SimpleFunc(void)
	{
		std::cout << "2" << std::endl;
	}
}

namespace BestComImp1
{
	void SimpleFunc(void)
	{
		std::cout << "1" << std::endl;
	}
	ProgcomImp1
	
}

int main(void)
{
	BestComImp1::SimpleFunc();
	BestComImp1::ProgcomImp1::SimpleFunc();
	return (0);
}