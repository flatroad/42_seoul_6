#include "InputFile.hpp"

InputFile::InputFile(char *input_file, char *check_str, char *tran_str):input_file_(input_file),check_str_(check_str),tran_str_(tran_str)
{
	start_ = 0;
	end_ = 0;
}

InputFile::~InputFile()
{
	std::cout << "goodbye InputFile" << std::endl;
}

int	InputFile::check_file()
{
	if (!(this->input_file_.is_open()))
	{
		std::cout << "File not found." << std::endl;
		return (1);
	}
	return (0);
}

void	InputFile::set_contents()
{
	std::string	buf;
	getline(this->input_file_, buf);
	while (this->input_file_)
	{
		this->contents_.append(buf);
		this->contents_.append("\n");
		getline(this->input_file_, buf);
	}
	std::cout << this->contents_ << std::endl;
}

int InputFile::check_end()
{
	if (this->end_ == -1)
		return (0);
	else
		return (1);
}

std::string	InputFile::send_str()
{
	this->end_ = this->contents_.find(this->check_str_, start_);
	if (this->end_ == std::string::npos)
		return (this->contents_.substr(this->start_));
	else if
		

}
