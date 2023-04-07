#ifndef INPUTFILE_HPP
# define INPUTFILE_HPP

#include <fstream>
#include <iostream>
#include <string>

class InputFile
{
	private:
		std::ifstream	input_file_;
		std::string		check_str_;
		std::string		contents_;
		int				start_;
		int				end_;
	public:
		InputFile(char *input_file, char *check_str, char *tran_str);
		~InputFile();
		int		check_file();
		void	set_contents();
		int		check_end();
		std::string	send_str();
};

#endif
