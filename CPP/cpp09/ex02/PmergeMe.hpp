#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>

#define True 1
#define False 0

typedef std::vector<int>	vector;
typedef std::list<int>		list;
typedef std::istringstream	istringstream;
typedef std::string			string;
typedef std::stringstream	stringstream;

class PM
{
	private:
		std::string	str_;
		vector		v_;
		list		lst_;
		bool	checkSameNumber(vector cp_v);
		bool	checkIsNumber(string s);
		int		convertInt(string s);
	public:
		PM(std::string str);
		~PM();
		void	checkIfYouCanStart();
		void	printVector();
		// void	printlist();
};

#endif