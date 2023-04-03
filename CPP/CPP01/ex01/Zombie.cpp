#include "Zombie.hpp"

void	Zombie::announce()
{
	std::cout << Zombie::name_ << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name)
{
	this->name_ = name;
}

Zombie::Zombie() {};

Zombie::~Zombie() 
{
	std::cout << this->name_ << " is die" << std::endl;
}
