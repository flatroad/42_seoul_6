#include "ClapTrap.hpp"

int main()
{
	ClapTrap	a("first");
	ClapTrap	b("second");

	a.attack("second");
	b.takeDamage(0);
	a.beRepaired(0);
	a.beRepaired(0);
	a.beRepaired(0);
	a.beRepaired(0);
	a.beRepaired(0);
	b.attack("first");
	a.takeDamage(0);
	a.beRepaired(0);
	a.beRepaired(0);
	a.beRepaired(0);
	a.beRepaired(0);
	a.beRepaired(0);
	a.attack("second");
	b.attack("first");
}