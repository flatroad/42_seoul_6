#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include <ctime>

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
		char		**argv_;
		int			argc_;
		vector		v_;
		list		lst_;
		bool	checkSameNumber(vector cp_v);
		bool	checkIsNumber(string s);
		int		convertInt(string s);
		void	makeList();
		clock_t	currentTime();
	public:
		PM(int argc, char **argv);
		~PM();
		void	checkIfYouCanStart();
		void	printVector();
		void	printList();
		double	fordJohnsonVector();
		double	fordJohnsonList();
};

#endif