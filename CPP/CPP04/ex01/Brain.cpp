#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default Brain Constructor" << std::endl;
}

Brain::Brain(const Brain& obj)
{
	std::cout << "Copy Brain Constructor" << std::endl;
	operator=(obj);
}

Brain &Brain::operator=(const Brain& obj)
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		for (int i = 0; i < 100; i++)
		{
			this->idea_[i] = obj.idea_[i];
		}
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Cat Destructor called" << std::endl;
}
