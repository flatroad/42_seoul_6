#include "TranStr.hpp"

TranStr::TranStr(char *tran_str):tran_str_(tran_str){};

TranStr::~TranStr()
{
	std::cout << "do tran" << std::endl;
}

std::string	TranStr::do_tran()