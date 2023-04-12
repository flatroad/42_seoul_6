#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Default Animal Constructor" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj)
{
	std::cout << "copy WrongCat Constructor" << std::endl;
	operator=(obj);
}

WrongCat &WrongCat::operator=(const WrongCat& obj)
{
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->setType(obj.getType());
	}
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "..." << std::endl;
}