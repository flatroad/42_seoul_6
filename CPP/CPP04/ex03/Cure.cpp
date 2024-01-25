#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {};

Cure::Cure(const Cure &obj)
{
  operator=(obj);
}

Cure &Cure::operator=(const Cure &obj)
{
  if (this != &obj)
  {
    this->AMateria::operator=(obj);
  }
  return (*this);
};

Cure::~Cure()
{
  std::cout << "bye Cure" << std::endl;
}


Cure* Cure::clone() const
{
  return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
  std::cout <<  "* heals " << target.getName() << "’s wounds *" << std::endl;
}