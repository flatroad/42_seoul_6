#include <iostream>
#include <vector>
#include <sstream>
#include <string>

int main()
{
	std::string s = "12 ";
	std::istringstream	istr(s);
	double	num;
	istr >> num;
	if (num > 21474836348)
		std::cout << "int overflow~" << std::endl;
	else if (istr.fail() == 1)
		std::cout << "fail" << std::endl;
	else if (istr.eof() == 0)
		std::cout << "eof" << std::endl;
	else
		std::cout << num << std::endl;
}