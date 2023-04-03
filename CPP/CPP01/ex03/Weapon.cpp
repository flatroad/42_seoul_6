#include "Weapon.hpp"

Weapon::Weapon(std::string att_type)
{
	this->att_type_ = att_type;
}

Weapon::~Weapon()
{
	std::cout << this->att_type_ << "is broken.." << std::endl;
}

const std::string &Weapon::getType() const
{
	return (this->att_type_);
}

void	Weapon::setType(std::string att_type)
{
	this->att_type_ = att_type;
}
