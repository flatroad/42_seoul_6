#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <iomanip>

#define ERROR 0
#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define NANN 5
#define INF 6
#define MINF 7
#define NANF 8
#define INFF 9
#define MINFF 9

class ScalarConverter
{
	private :
		std::string str_;
		size_t str_size_;
		double d_value_;
		int type_;
	public :
		ScalarConverter(const char *str);
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter& operator=(const ScalarConverter& obj);
		~ScalarConverter();
		void print_ScalarConvert();
		char convert_char();
		int convert_int() const;
		float convert_float();
		double convert_double(int a);
		void print_char();
		void print_int();
		void print_float();
		void print_double();
		void check_type();
		std::string get_value() const;
};

#endif