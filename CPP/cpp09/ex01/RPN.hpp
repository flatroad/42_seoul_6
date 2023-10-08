#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <deque>

#define True 1
#define False 0

typedef	std::stack<size_t> stack;
typedef	std::deque<int> deque;

class RPN
{
	private:
		void	(RPN::*ptrFunc[4])(int first, int second);
		void	plus(int first, int second);
		void	minus(int first, int second);
		void	mul(int first, int second);
		void	div(int first, int second);
		stack	stk;
		deque	deq;
		void	checkInt(std::string s);
		void	modifyStk(int idx);
		int		checkSystem(std::string s);
		int		checkFirstStkFactor(std::string s);
	public:
		RPN(const char *s);
		~RPN();
		RPN(const RPN& obj);
		RPN &operator=(const RPN& obj);
		int	calcRPN();
};

#endif