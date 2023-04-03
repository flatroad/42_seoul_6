#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &wp):name_(name),wp_(wp){}

HumanA::~HumanA()
{
	std::cout << this->name_ << "is die" << std::endl;
}

void	HumanA::attack()
{
	std::cout << this->name_ << this->wp_.getType() << "attack" << std::endl;
}
