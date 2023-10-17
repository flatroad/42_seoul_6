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

void	PM::mergeDiviveVector(std::vector<pair> &vec, int left, int right)
{
	if (left < right)
	{
		int mid = left + ((right - left) / 2);
		this->mergeDiviveVector(vec, left, mid);
		this->mergeDiviveVector(vec, mid + 1, right);

		mergeVector(vec, left, mid, right);
	}
}

void	PM::mergeVector(std::vector<pair> &vec, int left, int mid, int right)
{
	int	leftIdx = mid - left + 1;
	int	rightIdx = right - mid;

	std::vector<pair>	leftArea(leftIdx);
	std::vector<pair>	rightArea(rightIdx);

	for (int i = 0; i < leftIdx; i++)
		leftArea[i] = vec[left + i];
	for (int i = 0; i < rightIdx; i++)
		rightArea[i] = vec[mid + i + 1];

	int idx = left;
	left = 0;
	right = 0;
	while (left < leftIdx && right < rightIdx)
	{
		if (leftArea[left].first <= rightArea[right].first)
		{
			vec[idx] = leftArea[left];
			left++;
		}
		else
		{
			vec[idx] = rightArea[right];
			right++;
		}
		idx++;
	}

	while (left < leftIdx)
	{
		vec[idx] = leftArea[left];
		idx++;
		left++;
	}
	while (right < rightIdx)
	{
		vec[idx] = rightArea[right];
		idx++;
		right++;
	}
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
	this->mergeDiviveVector(vec, 0, vec.size() - 1);
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

void	PM::mergeDiviveList(std::list<pair> &lst)
{
	if (lst.size() <= 1)
		return ;
	
	std::list<pair>::iterator midIt = lst.begin();
	std::advance(midIt, lst.size() / 2);

	std::list<pair> leftList(lst.begin(), midIt);
	std::list<pair> rightList(midIt, lst.end());

	mergeDiviveList(leftList);
	mergeDiviveList(rightList);

	mergeList(lst.begin(), midIt, lst.end());
}

void	PM::mergeList(std::list<pair>::iterator leftIt, std::list<pair>::iterator midIt, std::list<pair>::iterator rightIt)
{
	std::list<pair> leftList(leftIt, midIt);
	std::list<pair> rightList(midIt, rightIt);

	std::list<pair>::iterator it = leftIt;
	leftIt = leftList.begin();
	rightIt = rightList.begin();

	while (leftIt != leftList.end() && rightIt != rightList.end())
	{
		if ((*leftIt).first <= (*rightIt).first)
		{
			(*it) =	(*leftIt);
			leftIt++;
		}
		else
		{
			(*it) = (*rightIt);
			rightIt++;
		}
		it++;
	}

	while (leftIt != leftList.end())
	{
		(*it) = (*leftIt);
		it++;
		leftIt++;
	}
	while (rightIt != rightList.end())
	{
		(*it) = (*rightIt);
		it++;
		rightIt++;
	}
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
	this->mergeDiviveList(lst);
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