#include "Dog.hpp"

Dog::Dog():Animal("Dog")
{
	std::cout << "Dog Default Animal Constructor" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog& obj)
{
	std::cout << "copy Dog Constructor" << std::endl;
	operator=(obj);
}

Dog &Dog::operator=(const Dog& obj)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->setType(obj.getType());
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "bow bow~" << std::endl;
}
