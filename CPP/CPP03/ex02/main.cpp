#include "FragTrap.hpp"

int main()
{
	FragTrap b("a");
	FragTrap a(b);

	a.highFivesGuys();
	a.attack("b");
	a.beRepaired(10);
	a.takeDamage(10);
}
