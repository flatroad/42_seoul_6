#include "ScavTrap.hpp"

int main()
{
	ScavTrap b("a");
	ScavTrap a(b);

	a.guardGate();
}
