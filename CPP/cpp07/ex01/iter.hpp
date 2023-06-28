#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T, typename func>
void iter(T* arr_addr, std::size_t arr_len, func f)
{
	for(std::size_t i = 0; i < arr_len; i++)
		f(arr_addr[i]);
}

// template<typename T>
// void print_1(const T& value)
// {
// 	std::cout << value << std::endl;
// }

// template<>
// void print_1<double>(const double& value)
// {
// 	std::cout << static_cast<int>(value) << std::endl;
// }

#endif