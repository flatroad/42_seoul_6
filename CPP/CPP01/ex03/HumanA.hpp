#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name_;
		Weapon &wp_;
	public:
		HumanA(std::string name, Weapon &wp);
		~HumanA();
		void	attack();
};

#endif
