#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name_;
		Weapon *wp_;
	public:
		HumanB(std::string name);
		~HumanB();
		void	setWeapon(Weapon &wp);
		void	attack();
};

#endif
