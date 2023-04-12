#include "Cat.hpp"

Cat::Cat():Animal("Cat")
{
	std::cout << "Cat Default Animal Constructor" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat& obj)
{
	std::cout << "copy Cat Constructor" << std::endl;
	operator=(obj);
}

Cat &Cat::operator=(const Cat& obj)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->setType(obj.getType());
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "..." << std::endl;
}