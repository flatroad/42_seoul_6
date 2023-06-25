#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base
{
	public:
		virtual ~Base()
		{
			std::cout << "base destructor" << std::endl;
		}
};

#endif