#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string	name_;
	public:
		Zombie (std::string name);
		~Zombie();
		void announce();
};

Zombie* zombieHorde( int N, std::string name );

#endif
