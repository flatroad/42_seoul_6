#ifndef OUTPUTFILE_HPP
# define OUTPUTFILE_HPP

#include <fstream>
#include <iostream>
#include <string>

class OutputFile
{
	private:
		std::ofstream	output_file_;
	public:
		OutputFile(char *output_file);
		~OutputFile();
		int	check_file();
};

#endif
