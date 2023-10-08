#include "RPN.hpp"

RPN::RPN(const char *s)
{
	std::string	str(s);
	std::istringstream ss(str);
	std::string memo;
	while (std::getline(ss, memo, ' '))
	{
		this->queue.push(memo);
	}
}