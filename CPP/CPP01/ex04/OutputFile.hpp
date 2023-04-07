#ifndef OUTPUTFILE_HPP
# define OUTPUTFILE_HPP

#include <fstream>
#include <iostream>
#include <string>

class OutputFile
{
	private:
		std::ifstream	output_file_;
	public:
		OutputFile(char *output_file);
		~OutputFile();
		int	check_file();
		void	set_contents();
};

#endif
