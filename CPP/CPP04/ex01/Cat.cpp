#include "Cat.hpp"

Cat::Cat():Animal("Cat")
{
	this->attr_ = new Brain;
	std::cout << "Cat Default Animal Constructor" << std::endl;
}

Cat::~Cat()
{
	delete this->attr_;
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
		this->attr_ = obj.attr_;
		this->setType(obj.getType());
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "..." << std::endl;
}

void	Cat::ad_attr()
{
	std::cout << &this->attr_ << std::endl;
}
