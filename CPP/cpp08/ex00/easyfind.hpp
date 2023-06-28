#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template<typename T>
typename T::iterator easyfind(T &arr, int i)
{
	typename T::iterator it;
	it = std::find(arr.begin(), arr.end(), i);
	if (it == arr.end())
		throw ("over index");
	return (it);
}

#endif