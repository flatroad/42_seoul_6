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
		bool			firstcheckProperData(std::string str, char a); 
	public:
		BERICH(char *str);
		~BERICH();
		void	checkOpenFile();
		void	checkProperData(char a, std::ifstream file);
		std::ifstream	&getInputFile();
		std::ifstream	&getDateBase();
};


#endif