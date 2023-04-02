#include "Zombie.hpp"

void	Zombie::announce()
{
	std::cout << Zombie::name_ << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie (std::string name) {this->name_ = name;}

Zombie::~Zombie() {std::cout << this->name_ << " is die" << std::endl;}