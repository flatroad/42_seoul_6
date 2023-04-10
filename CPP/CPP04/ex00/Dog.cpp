#include "Dog.hpp"

Dog::Dog():Animal("Dog")
{
	std::cout << "Dog Default Animal Constructor" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Animal Destructor called" << std::endl;
}

Dog::Dog(const Dog& obj)
{

}

Dog &Dog::operator=(const Dog& obj)
{

}

void	Dog::makeSound() virtual
{

}