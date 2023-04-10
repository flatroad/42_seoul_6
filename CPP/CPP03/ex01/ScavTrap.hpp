#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:

	public:
		ScavTrap(std::string Name);
		~ScavTrap();
		ScavTrap(const ScavTrap& obj);
		ScavTrap &operator=(const ScavTrap& obj);
		void guardGate();
};		

#endif