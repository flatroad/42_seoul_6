#ifndef COMMONFN_HPP
# define COMMONFN_HPP

#include <iostream>
#include <string>

std::string	transToupper(std::string s)
{
	std::string	str = s;
	for (int j = 0; str[j]; j++)
		str[j] = std::toupper(str[j]);
	return (str);
}

#endif
