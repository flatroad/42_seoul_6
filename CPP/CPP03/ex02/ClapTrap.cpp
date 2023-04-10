#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string Name):Name_(Name),HitPoints_(10),EnergyPoints_(10),AttackDamage_(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
};

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	operator=(obj);
}

ClapTrap &ClapTrap::operator=(const ClapTrap& obj)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->Name_ = obj.Name_;
		this->HitPoints_ = obj.HitPoints_;
		this->EnergyPoints_ = obj.EnergyPoints_;
		this->AttackDamage_ = obj.AttackDamage_;
	}
	return (*this);
}
void ClapTrap::setName(std::string Name)
{
	this->Name_ = Name;
}

void ClapTrap::setHitPoints(int HitPoints)
{
	this->HitPoints_ = HitPoints;
}

void ClapTrap::setEnergyPoints(int EnergyPoints)
{
	this->EnergyPoints_ = EnergyPoints;
}

void ClapTrap::setAttackDamage(int AttackDamage)
{
	this->AttackDamage_ = AttackDamage;
}

std::string ClapTrap::getName() const
{
	return (this->Name_);
}

int ClapTrap::getHitPoints() const
{
	return (this->HitPoints_);
}

int ClapTrap::getEnergyPoints() const
{
	return (this->EnergyPoints_);
}

int ClapTrap::getAttackDamage() const
{
	return (this->AttackDamage_);
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