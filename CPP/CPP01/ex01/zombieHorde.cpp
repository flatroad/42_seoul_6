#include "Zombie.hpp"

Zombie* zombieHorde(int N , std::string name)
{
	Zombie *Zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		Zombies[i].set_name(name);
		Zombies[i].announce();
	}
	return (Zombies);
}
