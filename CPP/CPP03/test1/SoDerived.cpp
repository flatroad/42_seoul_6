#include "SoDerived.hpp"

SoDerived::SoDerived() : derivNum(30)
{
	std::cout << "SoDervied 디폴트 생성자 호출" << std::endl;
}

SoDerived::SoDerived(int n) : derivNum(n)
{
	std::cout << "SoDervied 생성자 호출" << std::endl;
}
SoDerived::SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2)
{
	std::cout << "SoDervied와 SoBase 생성자 호출" << std::endl;
}

SoDerived::~SoDerived()
{
	std::cout << "SoDervied 소멸자 호출" << std::endl;
}

void SoDerived::ShowDerivDate()
{
	ShowBaseDate();
	std::cout << this->derivNum << std::endl;
}
