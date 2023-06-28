#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
	private :
		unsigned int N_;
		std::vector<int> arr_;
	public :
		Span(unsigned int N);
		Span(const Span& obj);
		Span &operator=(const Span& obj);
		~Span();
		void addNumber(int a);
		int shortestSpan();
		int longestSpan();
		void fill_arr(unsigned int a);
};


#endif