#include "Span.hpp"
#include <ctime>
#include <cstdlib>

Span::Span(unsigned int N) : N_(N){}

Span::Span(const Span& obj) : N_(obj.N_)
{
	this->arr_ = obj.arr_;
}

Span &Span::operator=(const Span& obj)
{
	if (this != &obj)
	{
		this->arr_ = obj.arr_;
		this->N_ = obj.N_;
	}
	return (*this);
}
Span::~Span(){}

void Span::addNumber(int a)
{
	if (this->arr_.size() >= this->N_)
		throw ("over index");
	this->arr_.push_back(a);
}

int Span::longestSpan()
{
	if (this->arr_.size() <= 1)
		throw("longestSpan is imposible");
	std::vector<int> arr_copy;
	arr_copy = this->arr_;
	std::sort(arr_copy.begin(), arr_copy.end());
	std::vector<int>::iterator start = arr_copy.begin();
	std::vector<int>::iterator end = arr_copy.end();
	return (*(--end) - *(start));
}

int Span::shortestSpan()
{
	if (this->arr_.size() <= 1)
		throw("shorttestSpan is imposible");
	std::vector<int> arr_copy;
	arr_copy = this->arr_;
	std::sort(arr_copy.begin(), arr_copy.end());
	int num = 0;
	std::vector<int>::iterator start = arr_copy.begin();
	std::vector<int>::iterator it = start;
	std::vector<int>::iterator end = arr_copy.end();
	for (; it != end; it++)
	{
		if (it + 1 != end)
		{
			if (num < (*it) + (*(it + 1)))
				num = (*it) + (*(it + 1));
		}
	}
	return (num);
}
void Span::fill_arr(unsigned int a)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	for (unsigned int i = 0; i < a; i++)
	{
		if (this->arr_.size() >= this->N_)
			throw ("index out");
		this->arr_.push_back(rand() % 10000);
	}
}