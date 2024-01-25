#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {};

Ice::Ice(const Ice &obj)
{
  operator=(obj);
}

Ice &Ice::operator=(const Ice &obj)
{
  if (this != &obj)
  {
    this->AMateria::operator=(obj);
  }
  return (*this);
}

Ice::~Ice()
{
  std::cout << "bye Ice" << std::endl;
}


Ice* Ice::clone() const
{
  return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
  std::cout <<  "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}