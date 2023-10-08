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


PM::PM(const PM& obj)
{
	operator=(obj);
}

PM	&PM::operator=(const PM& obj)
{
	if (this != &obj)
	{
		this->argv_ = obj.argv_;
		this->argc_ = obj.argc_;
		this->count_ = obj.count_;
		this->v_ = obj.v_;
		this->lst_ = obj.lst_;
	}
	return (*this);
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
	this->countNumber();
	this->makeList();
}

void	PM::countNumber()
{
	vector::iterator it;
	int	count = 0;
	for (it = this->v_.begin(); it != this->v_.end(); it++)
		count = count + 1;
	this->count_ = count;
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
	clock_t	start_t = clock();
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
	vector::iterator	that;
	for (it = vec.begin(); it != vec.end(); it++)
	{
		that = std::lower_bound(ans_vec.begin(), ans_vec.end(), (*it).second);
		ans_vec.insert(that, (*it).second);
		ans_vec.push_back((*it).first);
	}
	if (ans_vec[0] == -1)
		ans_vec.erase(ans_vec.begin());
	this->v_ = ans_vec;
	clock_t	end_t = clock();
	double	calc_time = static_cast<double>(end_t - start_t) / CLOCKS_PER_SEC;
	std::cout << calc_time * 1000000.0 << " μs" << std::endl;
	return (1.1);
}

double	PM::fordJohnsonList()
{
	int	i = 0;
	std::list<pair>		lst;
	list				ans_lst;
	clock_t	start_t = clock();
	if (this->count_ % 2 == 1 || this->count_ == 1)
	{
		lst.push_back(std::make_pair(-1, this->v_[0]));
		i = 1;
	}
	while (i < this->count_)
	{
		lst.push_back(std::make_pair(this->v_[i], this->v_[i + 1]));
		i = i + 2;
	}
	std::list<pair>::iterator it;
	for (it = lst.begin(); it != lst.end(); it++)
	{
		if ((*it).first < (*it).second)
		{
			int memo = (*it).first;
			(*it).first = (*it).second;
			(*it).second = memo;
		}
	}
	lst.sort(sortFirst);
	list::iterator	that;
	for (it = lst.begin(); it != lst.end(); it++)
	{
		that = std::lower_bound(ans_lst.begin(), ans_lst.end(), (*it).second);
		ans_lst.insert(that, (*it).second);
		ans_lst.push_back((*it).first);
	}
	if (*(ans_lst.begin()) == -1)
		ans_lst.erase(ans_lst.begin());
	this->lst_ = ans_lst;
	clock_t	end_t = clock();
	double	calc_time = static_cast<double>(end_t - start_t) / CLOCKS_PER_SEC;
	std::cout << calc_time * 1000000.0 << " μs" << std::endl;
	return (1.1);
}

int	PM::getCount()
{
	return (this->count_);
}