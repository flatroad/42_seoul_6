#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj.getName())
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	operator=(obj);
}

ScavTrap &ScavTrap::operator=(const ScavTrap& obj)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->setName(obj.getName());
		this->setHitPoints(obj.getHitPoints());
		this->setEnergyPoints(obj.getEnergyPoints());
		this->setAttackDamage(obj.getAttackDamage());
	}
	return (*this);
}

void ScavTrap::guardGate()
{
	std::cout << "Scavtrap " << this->getName() << " Gate keeper mode" << std::endl;
}