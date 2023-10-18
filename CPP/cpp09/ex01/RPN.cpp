#include "RPN.hpp"

RPN::RPN(const char *s)
{
	ptrFunc[0] = &RPN::plus;
	ptrFunc[1] = &RPN::minus;
	ptrFunc[2] = &RPN::mul;
	ptrFunc[3] = &RPN::div;
	std::string	str(s);
	std::istringstream istr(str);
	std::string memo;

	while (std::getline(istr, memo, ' '))
		this->deq.push_back(this->checkSystem(memo));
	if (deq.size() == 0)
		throw ("no exist");
}

RPN::~RPN(){}

RPN::RPN(const RPN& obj)
{
	operator=(obj);
}

RPN	&RPN::operator=(const RPN& obj)
{
	if (this != &obj)
	{
		ptrFunc[0] = &RPN::plus;
		ptrFunc[1] = &RPN::minus;
		ptrFunc[2] = &RPN::mul;
		ptrFunc[3] = &RPN::div;
		this->deq = obj.deq;
		this->stk = obj.stk;
	}
	return (*this);
}

int	RPN::checkSystem(std::string s)
{
	if (s.compare("+") == 0)
		return (11);
	else if (s.compare("-") == 0)
		return (12);
	else if (s.compare("*") == 0)
		return (13);
	else if (s.compare("/") == 0)
		return (14);
	else
	{
		return (this->checkFirstStkFactor(s));
	}
}

int	RPN::checkFirstStkFactor(std::string s)
{
	std::istringstream	istr(s);
	int	num;
	istr >> num;
	
	if (istr.fail() == True)
		throw ("Error, factor that violates the rules");
	if (istr.eof() == False)
		throw ("Error, factor that violates the rules");
	if (num > 9)
		throw ("foctor is too high");
	if (num < -9)
		throw ("factor is too lower");
	return (num);
}

int	RPN::calcRPN()
{
	while(this->deq.empty() != True)
	{
		int c = deq.front();
		deq.pop_front();
		if (c >= 11 && c <= 14)
		{
			if (stk.size() < 2)
				throw ("2 under stk");
			this->modifyStk(c - 11);
		}
		else
			this->stk.push(c);
	}
	if (stk.size() != 1)
		throw ("There are more than 2 left on the stack.");
	return (stk.top());
}

void	RPN::modifyStk(int idx)
{
	int first = 0;
	int second = 0;
	second = this->stk.top();
	this->stk.pop();
	first = this->stk.top();
	this->stk.pop();
	(this->*ptrFunc[idx])(first, second);
}

void	RPN::plus(int first, int second)
{
	this->stk.push(first + second);
}

void	RPN::minus(int first, int second)
{
	this->stk.push(first - second);
}

void	RPN::mul(int first, int second)
{
	this->stk.push(first * second);
}

void	RPN::div(int first, int second)
{
	if (second == 0)
		throw (first);
	else
	{
		this->stk.push(static_cast<int>(first / second));
	}
}