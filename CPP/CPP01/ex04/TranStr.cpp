#include "TranStr.hpp"

TranStr::TranStr(char *tran_str):tran_str_(tran_str)
{
	std::cout << "hello, TranStr" << std::endl;
}

TranStr::~TranStr()
{
	std::cout << "bye TranStr" << std::endl;
}

std::string	TranStr::do_tran(t_send_str data)
{
	if (data.i == 1)
		return (this->tran_str_);
	else
		return (data.str);
}
