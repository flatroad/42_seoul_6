#include "OutputFile.hpp"

OutputFile::OutputFile(std::string output_file):output_file_(output_file)
{
	std::cout << "hello, OutputFile" << std::endl;
}

OutputFile::~OutputFile()
{
	std::cout << "goodbye OutputFile" << std::endl;
}

int	OutputFile::check_file()
{
	if (!(this->output_file_.is_open()))
	{
		std::cout << "OutFile not found." << std::endl;
		return (1);
	}
	return (0);
}

void	OutputFile::add_file(std::string save)
{
	this->output_file_ << save;
}
