#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>(){}
		MutantStack(const MutantStack &obj) : std::stack<T>(obj){}
		MutantStack &operator=(const MutantStack &obj)
		{
			if (this != &obj)
			{
				std::stack<T>::operator=(obj);
			}
			return (*this);
		}
		~MutantStack(){};
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		// typename std::deque<T>::
		iterator begin();
		iterator end();
		reverse_iterator rend();
		reverse_iterator rbegin();
};

#include "MutantStack.tpp"

#endif