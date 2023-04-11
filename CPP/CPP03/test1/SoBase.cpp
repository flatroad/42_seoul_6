#include "SoBase.hpp"

SoBase::SoBase():baseNum(20)
{
	std::cout << "baseNum 디폴트 생성자 발생" << std::endl;
}

SoBase::SoBase(int n) : baseNum(n)
{
	std::cout << "baseNum 생성자 발생" << std::endl;
}

SoBase::~SoBase()
{
	std::cout << "SoBase 소멸자 호출" << std::endl;
}

void SoBase::ShowBaseDate()
{
	 std::cout << baseNum << std::endl;
}
