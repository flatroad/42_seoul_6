#ifndef INPUTFILE_HPP
# define INPUTFILE_HPP

#include <fstream>
#include <iostream>
#include <string>
#include "SendStr.hpp"

class InputFile
{
	private:
		std::ifstream	input_file_;
		std::string		check_str_;
		std::string		contents_;
		int				start_;
		int				end_;
		int				check_str_len;
	public:
		InputFile(char *input_file, char *check_str);
		~InputFile();
		int		check_file();
		void	set_contents();
		void	set_str_len();
		int		check_end();
		t_send_str	send_str();
};

#endif
