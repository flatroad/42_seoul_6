#ifndef SODERIVED_HPP
# define SODERIVED_HPP

#include "SoBase.hpp"

class SoDerived : public SoBase
{
	private :
		int derivNum;
	public :
		SoDerived();
		SoDerived(int n);
		SoDerived(int n1, int n2);
		~SoDerived();
		void ShowDerivDate();
};


#endif
