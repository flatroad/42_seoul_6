#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap b("b");
	DiamondTrap c = b;
	
	c = b;

	c.highFivesGuys();
	c.guardGate();
	c.print_setting();
}
