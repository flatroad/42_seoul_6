#include "PmergeMe.hpp"

PM::PM(std::string str)
{
	this->str_ = str;
}

PM::~PM()
{
	std::cout << "exit" << std::endl;
}	

void	PM::checkIfYouCanStart()
{
	string			memo;
	istringstream	temp(this->str_);
	while (getline(temp, memo, ' '))
	{
		if (checkIsNumber(memo) == False)
			throw ("is worng obj");
		this->v_.push_back(this->convertInt(memo));
	}
	vector cp_v(this->v_.begin(), this->v_.end());
	if (this->checkSameNumber(cp_v) == False)
		throw ("have a same number");
}

bool	PM::checkSameNumber(vector cp_v)
{
	std::sort(cp_v.begin(), cp_v.end());
	vector::iterator it;
	int memo = -1;
	for (it = cp_v.begin(); it != cp_v.end(); it++)
	{
		if (memo == *it)
			return (False);
	}
	return (True);
}

bool	PM::checkIsNumber(string s)
{
	istringstream	istr(s);
	double	num;
	istr >> num;
	if (num > 2147483647)
		return (False);
	if (istr.fail() == True)
		return (False);
	if (istr.eof() == False)
		return (False);
	return (True);
}

int PM::convertInt(string s)
{
	istringstream	istr(s);
	int	num;
	istr >> num;
	return (num);
}

void	PM::printVector()
{
	vector::iterator it;
	for (it = this->v_.begin(); it != this->v_.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}