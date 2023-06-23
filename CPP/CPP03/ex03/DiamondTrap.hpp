#ifndef DIAMINDTRAP_HPP
#define DIAMINDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private :
		std::string Name_;
	public :
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap(const DiamondTrap& obj);
		DiamondTrap &operator=(const DiamondTrap& obj);
		void whoAmI();
		void print_setting();
};

#endif