#include "PmergeMe.hpp"

PM::PM(int argc, char **argv)
{
	this->argc_ = argc;
	this->argv_ = argv;
}

PM::~PM()
{
	std::cout << "exit" << std::endl;
}	

void	PM::checkIfYouCanStart()
{
	char	**argv = ++this->argv_;

	for (int i = 1; i < this->argc_; i++)
	{
		string memo(*argv);
		if (checkIsNumber(memo) == False)
			throw ("Error, is worng obj");
		this->v_.push_back(this->convertInt(memo));
		argv++;
	}
	vector cp_v(this->v_.begin(), this->v_.end());
	if (this->checkSameNumber(cp_v) == False)
		throw ("Error, have a same number");
	this->makeList();
}

bool	PM::checkSameNumber(vector cp_v)
{
	std::sort(cp_v.begin(), cp_v.end());
	vector::iterator it;
	int memo = -1;
	int	count = 0;
	for (it = cp_v.begin(); it != cp_v.end(); it++)
	{
		count = count + 1;
		if (memo == *it)
			return (False);
	}
	this->count_ = count;
	return (True);
}

bool	PM::checkIsNumber(string s)
{
	istringstream	istr(s);
	double	num;
	istr >> num;
	if (num > 2147483647)
		return (False);
	if (num < 0)
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

void	PM::printList()
{
	list::iterator it;
	for (it = this->lst_.begin(); it != this->lst_.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PM::makeList()
{
	list lst(this->v_.begin(), this->v_.end());
	this->lst_ = lst;
}

static bool sortFirst(pair &a, pair &b)
{
	return (a.first < b.first);
}

double	PM::fordJohnsonVector()
{
	int	i = 0;
	std::vector<pair>	vec;
	vector				ans_vec;
	// clock_t	start = this->currentTime();
	if (this->count_ % 2 == 1 || this->count_ == 1)
	{
		vec.push_back(std::make_pair(-1, this->v_[0]));
		i = 1;
	}
	while (i < this->count_)
	{
		vec.push_back(std::make_pair(this->v_[i], this->v_[i + 1]));
		i = i + 2;
	}
	std::vector<pair>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
	{
		if ((*it).first < (*it).second)
		{
			int memo = (*it).first;
			(*it).first = (*it).second;
			(*it).second = memo;
		}
	}
	std::sort(vec.begin(), vec.end(), sortFirst);

	for (int i = 0; i < (this->count_ / 2); i++)
	{
		std::cout << i << " : " << vec[i].first << ", "<< vec[i].second <<  std::endl;
	}
	ans_vec.push_back()
	// clock_t	end = this->currentTime();
	return (1.1);
}