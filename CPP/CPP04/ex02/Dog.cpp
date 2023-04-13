#include "Dog.hpp"

Dog::Dog():Animal("Dog")
{
	this->attr_ = new Brain;
	std::cout << "Dog Default Animal Constructor" << std::endl;
}

Dog::~Dog()
{
	delete this->attr_;
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
		*(this->attr_) = *(obj.attr_);
		this->setType(obj.getType());
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "bow bow~" << std::endl;
}

void	Dog::ad_attr()
{
	std::cout << &this->attr_ << std::endl;
}
