#include "Array.hpp"

template<typename T>
Array<T>::Array() : arr_(NULL), arr_size_(0){}

template<typename T>
Array<T>::Array(unsigned int n) : arr_size_(n)
{
	this->arr_ = new T[arr_size_];
}

template<typename T>
Array<T>::Array(const Array& obj)
{
	this->operator=(obj);
}


template<typename T>
Array<T>& Array<T>::operator=(const Array& obj)
{
	if (*this != obj)
	{
		if (this->arr_ != NULL)
			delete (this->arr_);
		arr_size_ = obj.arr_size_;
		this->arr_ = new T[this->arr_size_];
		for (unsigned int i = 0; i < this->arr_size_; i++)
		{
			this->arr_size_[i] = obj.arr_[i];
		}
	}
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	if (this->arr_ != NULL)
		delete[] this->arr_;
}

template<typename T>
T& Array<T>::operator[](unsigned int idx) const
{
	if (this->arr_size <= idx)
		throw (Array<T>::IndexOut());
	return (this->arr[idx]);
}

template<typename T>
const char *Array<T>::IndexOut::what() const throw()
{
	return ("index out");
}

template<typename T>
unsigned int Array<T>::size() const
{
	return (this->arr_size_);
}