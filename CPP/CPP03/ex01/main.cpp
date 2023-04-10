#include "ScavTrap.hpp"

int main()
{
	ScavTrap b("a");
	ScavTrap a(b);

	a.guardGate();
	a.attack("b");
	a.beRepaired(10);
	a.takeDamage(10);
}
