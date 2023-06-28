#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
	private :
		T* arr_;
		unsigned int arr_size_;
		class IndexOut : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
	public :
		Array();
		Array(unsigned int n);
		Array(const Array& obj);
		Array& operator=(const Array& obj);
		~Array();
		T& operator[](unsigned int idx) const;
		unsigned int size() const;
};

#endif