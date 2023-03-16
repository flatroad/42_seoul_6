#include <iostream>
#include <string>


int	main()
{
	std::string tempstr ="c++ 알고리즘이 재밌다!";
	std::string tempstr2 ="Java 알고리즘이 재밌다!";

	tempstr2 = tempstr; // tempstr2는 c++ 알고리즘이 재밌다로 덮어쓰기 된다.
	std::string str = tempstr+" 그리고 "+ tempstr2; // c++ 알고리즘이 재밌다! 그리고 java 알고리즘이 재밌다!
	std::cout << str << std::endl;
	return (0);
}