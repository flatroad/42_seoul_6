#include "Zombie.hpp"

void exec();

int main()
{
	exec();
	system("leaks Zombie");
	return (0);
}

void exec()
{
	Zombie *kk = zombieHorde(4, "zombie");
	delete []kk;
}
