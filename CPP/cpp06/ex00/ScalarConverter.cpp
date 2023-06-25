#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(const char *str)
{
	this->str_ = "";
	this->str_.append(str);
	this->str_size_ = str_.length();
}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
	this->str_ = obj.get_value();
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
	if (this != &obj)
	{
		this->str_ = obj.get_value();
	}
	return (*this);
}

std::string ScalarConverter::get_value() const
{
	return (this->str_);
}

ScalarConverter::~ScalarConverter(){}

void ScalarConverter::print_ScalarConvert()
{
	std::cout << "char : ";
	this->print_char();
	std::cout << "int : ";
	this->print_int();
	std::cout << "float : ";
	this->print_float();
	std::cout << "double : ";
	this->print_double();
}

void ScalarConverter::print_char()
{
	if (this->type_ == NANN || this->type_ == NANF || this->type_ == INF || this->type_ == INFF || this->type_ == MINF || this->type_ == MINFF)
		std::cout << "nan~ - impossible" << std::endl;
	else if (this->type_ == CHAR)
		std::cout << this->str_ << std::endl;
	else
	{
		if (this->d_value_ > 255 ||  this->d_value_ < 0)
		{
			std::cout << "over char - impossible" << std::endl;
			return ;
		}
		char c;
		c = convert_char();
		if (std::isprint(c) == 0)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << c << std::endl;
	}
}

void ScalarConverter::print_int()
{
	if (this->type_ == NANN || this->type_ == NANF || this->type_ == INF || this->type_ == INFF || this->type_ == MINF)
		std::cout << "nan~ - impossible" << std::endl;
	else if (this->type_ == CHAR)
		std::cout << convert_int() << std::endl;
	else
	{
		if (static_cast<long long>(this->d_value_) > 2147483647.0 || static_cast<long long>(this->d_value_) < -2147483648)
			std::cout << "over int - impossible" << std::endl;
		else
			std::cout << convert_int() << std::endl;
	}
}

void ScalarConverter::print_float()
{
	if (this->type_ == NANN || this->type_ == NANF)
		std::cout << "nanf" << std::endl;
	else if (this->type_ == INF || this->type_ == INFF)
		std::cout << "+inff" << std::endl;
	else if (this->type_ == MINF || this->type_ == MINFF)
		std::cout << "-inff" << std::endl;
	else if (this->convert_float() == static_cast<long long>(this->convert_float()))
	{
		size_t idx = 0;
		size_t i = this->str_.find('.');
		if (i == std::string::npos)
			i = this->str_size_;
		if (this->str_[0] == '+' || this->str_[0] == '-')
			idx = 1;
		if (i - idx > 6 && i - idx < 38)
			std::cout << this->convert_float() << "f" << std::endl;
		else
			std::cout << this->convert_float() << ".0f" << std::endl;
	}
	else
		std::cout << convert_float() << "f" << std::endl;
}

void ScalarConverter::print_double()
{
	if (this->type_ == NANN || this->type_ == NANF)
		std::cout << "nan" << std::endl;
	else if (this->type_ == INF || this->type_ == INFF)
		std::cout << "+inf" << std::endl;
	else if (this->type_ == MINF || this->type_ == MINFF)
		std::cout << "-inf" << std::endl;
	else if (this->d_value_ == static_cast<long long>(this->d_value_))
	{
		size_t idx = 0;
		size_t i = this->str_.find('.');
		if (i == std::string::npos)
			i = this->str_size_;
		if (this->str_[0] == '+' || this->str_[0] == '-')
			idx = 1;
		if (i - idx > 6)
			std::cout << this->d_value_ << std::endl;
		else
			std::cout << this->d_value_ << ".0" << std::endl;
	}
	else
		std::cout << this->d_value_ << std::endl;
		
}

void ScalarConverter::check_type()
{
	if (this->str_.compare("nan") == 0)
		this->type_ = NANN;
	else if (this->str_.compare("nanf") == 0)
		this->type_ = NANF;
	else if (this->str_.compare("-inf") == 0)
		this->type_ = MINF;
	else if (this->str_.compare("inf") == 0 || this->str_.compare("+inf") == 0)
		this->type_ = INF;
	else if (this->str_.compare("nanf") == 0)
		this->type_ = NANF;
	else if (this->str_.compare("-inff") == 0)
		this->type_ = MINFF;
	else if (this->str_.compare("inff") == 0 || this->str_.compare("+inff") == 0)
		this->type_ = INFF;
	else
	{
		double value = 0;
		char *ptr;
		if (this->str_size_ == 1)
		{
			if ((std::isdigit((this->str_.c_str())[0])) == true)
			{
				this->type_ = INT;
				this->d_value_ = convert_double(this->str_[0] - 48);
				return ;
			}
			if ((std::isprint((this->str_.c_str())[0])) == true)
			{
				this->type_ = CHAR;
				this->d_value_ = convert_double(this->str_[0]);
				return ;
			}
			throw ("parameter no good, convert fail1");
		}
		value = std::strtod(this->str_.c_str(), &ptr);
		if (value == 0 && this->str_[0] != '+' && this->str_[0] != '-' && (std::isdigit(this->str_[0]) == 0))
			throw ("parameter no good, convert fail2");
		if (*ptr != 0 && strcmp(ptr, "f"))
			throw ("parameter no good, convert fail3");
		this->d_value_ = value;
		if (this->str_.find('f') != std::string::npos)
		{
			this->type_ = FLOAT;
			return ;
		}
		if (this->str_.find('.') != std::string::npos)
		{
			this->type_ = DOUBLE;
			return ;
		}
		this->type_ = INT;
	}
}

char ScalarConverter::convert_char()
{
	return (static_cast<char>(this->d_value_));
}

int ScalarConverter::convert_int() const
{
	return (static_cast<int>(this->d_value_));
}

float ScalarConverter::convert_float()
{
	return (static_cast<float>(this->d_value_));
}

double ScalarConverter::convert_double(int a)
{
	return (static_cast<double>(a));
}