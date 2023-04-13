#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default Animal Constructor" << std::endl;
}

Animal::Animal(std::string type):type_(type)
{
	std::cout << type_ << " Animal Constructor" << std::endl;
}

Animal::Animal(const Animal& obj)
{
	std::cout << "copy Animal Constructor" << std::endl;
	operator=(obj);
}

Animal &Animal::operator=(const Animal& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->type_ = obj.type_;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

void Animal::setType(std::string type)
{
	this->type_ = type;
}

std::string const	Animal::getType() const 
{
	return (this->type_);
}
