#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{ 
	private:

	public:
		FragTrap(std::string Name);
		~FragTrap();
		FragTrap(const FragTrap& obj);
		FragTrap &operator=(const FragTrap& obj);
		void highFivesGuys(void);
};		

#endif