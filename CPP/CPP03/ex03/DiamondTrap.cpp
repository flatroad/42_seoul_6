#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
	this->Name_ = name;
	std::cout << FragTrap::ClapTrap::getHitPoints() << std::endl;
	std::cout << FragTrap::ClapTrap::getAttackDamage() << std::endl;
	std::cout << ScavTrap::ClapTrap::getHitPoints() << std::endl;
	std::cout << ScavTrap::ClapTrap::getAttackDamage() << std::endl;
	std::cout << ScavTrap::ClapTrap::getEnergyPoints() << std::endl;
	std::cout << ScavTrap::ClapTrap::getEnergyPoints() << std::endl;
	ClapTrap::setHitPoints(FragTrap::getHitPoints());
	ClapTrap::setAttackDamage(FragTrap::getAttackDamage());
};

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : ClapTrap(obj), FragTrap(obj), ScavTrap(obj)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& obj)
{
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->Name_ = obj.Name_;
		ClapTrap::operator=(obj);
	}
	return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout << "\nDiamond " << this->Name_ << "\nClap " << ClapTrap::getName() << "\n" << std::endl;
}

void DiamondTrap::print_setting()
{
	this->whoAmI();
	std::cout << "name " << this->getName() << std::endl;
	std::cout << "attact_damage " <<this->getAttackDamage() << std::endl;
	std::cout << "energy_point " <<this->getEnergyPoints() << std::endl;
	std::cout << "hit_point " <<this->getHitPoints() << std::endl;
}