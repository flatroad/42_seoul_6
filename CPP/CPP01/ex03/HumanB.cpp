#include "HumanB.hpp"

HumanB::HumanB(std::string name):name_(name){}

HumanB::~HumanB()
{
	std::cout << this->name_ << "is die" << std::endl;
}

void	HumanB::setWeapon(Weapon &wp)
{
	this->wp_ = &wp;
}

void	HumanB::attack()
{
	std::cout << this->name_ << this->wp_->getType() << "attack" << std::endl;
}
