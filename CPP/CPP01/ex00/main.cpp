#include "Zombie.hpp"

int main()
{
	Zombie F_Zombie("First");
	F_Zombie.announce();
	Zombie *S_Zombie = newZombie("Second");
	S_Zombie->announce();
	randomChump("Third");
	delete S_Zombie;
	
	return (0);
}
