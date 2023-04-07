#include "InputFile.hpp"

InputFile::InputFile(char *input_file, char *check_str):input_file_(input_file),check_str_(check_str)
{
	start_ = 0;
	end_ = 0;
	std::cout << "hello, InputFile" << std::endl;
}

InputFile::~InputFile()
{
	input_file_.close();
	std::cout << "goodbye InputFile" << std::endl;
}

int	InputFile::check_file()
{
	if (!(this->input_file_.is_open()))
	{
		std::cout << "InFile not found." << std::endl;
		return (1);
	}
	return (0);
}

void	InputFile::set_str_len()
{
	this->check_str_len = this->check_str_.length();
}

void	InputFile::set_contents()
{
	std::string	buf;
	while (getline(this->input_file_, buf))
	{
		this->contents_.append(buf);
		if (this->input_file_.eof())
			break;
		this->contents_.append("\n");
	}
}

int InputFile::check_end()
{
	if (this->end_ == -1)
		return (0);
	else
		return (1);
}

t_send_str	InputFile::send_str()
{
	int	check;
	t_send_str	send_list;
	check = this->contents_.find(this->check_str_, this->start_) - this->start_;
	if (check == -1 || this->check_str_len == 0)
	{
		send_list.str = this->contents_.substr(this->start_);
		this->end_ = -1;
		return (send_list);
	} 
	else if (check == 0)
	{
		this->end_ += (this->check_str_len);
		send_list.i = 1;
	}
	else
	{
		this->end_ += check;
		send_list.i = 0;
	}
	send_list.str = this->contents_.substr(this->start_, this->end_ - this->start_);
	this->start_ = this->end_;
	return (send_list);
}
