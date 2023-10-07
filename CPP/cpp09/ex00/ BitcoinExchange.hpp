#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>
#include <map>

#define True 1
#define False 0
#define	Database "data.csv"

typedef	std::map<int, double>	map;
typedef std::queue<std::string>	queue;

class BERICH
{
	private:
		std::ifstream	input_file_;
		std::ifstream	data_base_;
		map				input_;
		map				data_;
		bool			firstcheckProperDatabase(std::string str);
		queue			devideDatebaseDateValue(std::string str);
		int				devideDatebaseDate(std::string str);
		double			devideDatebaseValue(std::string str);
		bool			checkYear(std::string str);
		bool			checkMonth(std::string str);
		bool			checkDay(std::string str, std::string year, std::string month);
		bool			firstcheckProperInputfile(std::string str);
	public:
		BERICH(char *str);
		~BERICH();
		void			checkOpenFile();
		void			checkProperDatabase(std::ifstream &file);
		void			checkProperInputfile(std::ifstream &file);
		std::ifstream	&getInputFile();
		std::ifstream	&getDateBase();
};


#endif