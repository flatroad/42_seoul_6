#include " BitcoinExchange.hpp"

BERICH::BERICH(std::string str)
{
	std::ifstream	input_file(str);
	std::ifstream	data_base("data_base");
}

BERICH::~BERICH()
{
	std::cout << "exit" << std::endl;
}