#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default WrongAnimal Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type):type_(type)
{
	std::cout << type_ << " WrongAnimal Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
	std::cout << "copy WrongAnimal Constructor" << std::endl;
	operator=(obj);
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->type_ = obj.type_;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

void WrongAnimal::setType(std::string type)
{
	this->type_ = type;
}

std::string const	WrongAnimal::getType() const 
{
	return (this->type_);
}

void	WrongAnimal::makeSound () const
{
	std::cout << "animal~" << std::endl;
}
