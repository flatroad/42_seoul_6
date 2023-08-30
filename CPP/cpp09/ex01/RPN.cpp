#include "RPN.hpp"

Rpn::Rpn(std::string str)
{
	std::istringstream ss(str);
	std::string memo;
	while (std::getline(ss, memo, ' '))
	{
		this->queue.push(memo);
	}
}