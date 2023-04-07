#ifndef TRANSTR_HPP
# define TRANSTR_HPP

#include <fstream>
#include <iostream>
#include <string>

class TranStr
{
	private:
		std::string	tran_str_;
	public:
		TranStr(char *tran_str);
		~TranStr();
		std::string	do_tran();
};

#endif
