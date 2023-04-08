#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string Name):Name_(Name),HitPoints_(10),EnergyPoints_(10),AttackDamage_(0)
{
	std::cout << "constructor called" << std::endl;
};

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	std::cout << "Copy constructor called" << std::endl;
	operator=(obj);
}

ClapTrap &ClapTrap::operator=(const ClapTrap& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->Name_ = obj.Name_;
		this->HitPoints_ = obj.HitPoints_;
		this->EnergyPoints_ = obj.EnergyPoints_;
		this->AttackDamage_ = obj.AttackDamage_;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->HitPoints_ <= 0)
	{
		std::cout << "run out HitPoints_" << std::endl;
	}
	else if (this->EnergyPoints_ <= 0)
	{
		std::cout << "run out EnergyPoints_" << std::endl;
	}
	else
	{
		this->EnergyPoints_--;
		std::cout << this->Name_ << " attacts " << target << ", causing " << this->AttackDamage_ << " points of damage!" << std::endl;
		if (this->EnergyPoints_ == 0)
		{
			std::cout << this->Name_ << " use all EnergyPoints_" << std::endl; 
		}
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HitPoints_ <= 0)
	{
		std::cout << "He's dead. Don't waste your EnergyPoints_" << std::endl;
	}
	else
	{
		std::cout << this->Name_ << "attacted someone" << "lost HitPoints_" << amount << std::endl;
		this->HitPoints_ -= amount;
		if (this->HitPoints_ <= 0)
		{
			std::cout << this->Name_ << "is dead" <<std::endl;
		}
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->HitPoints_ <= 0)
	{
		std::cout << "run out HitPoints_" << std::endl;
	}
	else if (this->EnergyPoints_ <= 0)
	{
		std::cout << "run out EnergyPoints_" << std::endl;
	}
	else
	{
		this->EnergyPoints_--;
		std::cout << this->Name_ << " beRepaired " << amount << std::endl;
		if (this->EnergyPoints_ == 0)
		{
			std::cout << this->Name_ << " use all EnergyPoints_" << std::endl; 
		}
	}
}