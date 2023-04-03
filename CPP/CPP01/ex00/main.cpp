#include "Zombie.hpp"

void	exec();

int main()
{
	exec();
	system("leaks Zombie");	
	return (0);
}

void	exec()
{
	Zombie F_Zombie("First");
	F_Zombie.announce();
	Zombie *S_Zombie = newZombie("Second");
	S_Zombie->announce();
	randomChump("Third");
	delete S_Zombie;
}