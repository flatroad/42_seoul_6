#ifndef SOBASE_HPP
# define SOBASE_HPP

#include <iostream>

class SoBase
{
	private :
		int baseNum;
	public :
		SoBase();
		SoBase(int n);
		~SoBase();
		void ShowBaseDate();
};

#endif