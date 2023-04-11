#include "SoDerived.hpp"

int main()
{
	std::cout << "case1 ..." << std::endl;
	SoDerived dr1;
	dr1.ShowDerivDate();
	std::cout << "---------------" << std::endl;
	std::cout << "case2 ..." << std::endl;
	SoDerived dr2(12);
	dr2.ShowDerivDate();
	std::cout << "---------------" << std::endl;
	std::cout << "case3 ..." << std::endl;
	SoDerived dr3(23, 24);
	dr3.ShowDerivDate();
	return (0);
}
