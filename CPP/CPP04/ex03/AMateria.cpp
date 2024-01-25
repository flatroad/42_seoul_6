#include "AMateria.hpp"

AMateria::AMateria() : type_("none") {};

AMateria::AMateria(const std::string& type) : type_(type) {};

AMateria::AMateria(const AMateria& obj)
{
  operator=(obj);
}

AMateria &AMateria::operator=(const AMateria& obj)
{
  if (this != &obj)
  {
    this->type_ = obj.type_;
  }
  return (*this);
}

std::string const &AMateria::getType() const
{
  return (this->type_);
}

AMateria::~AMateria()
{
}


void AMateria::use(ICharacter& target)
{
  std::cout << target.getName() << " 일단 유감스럽게도 에상치 못한 결과가 나올겁니다" << std::endl;
}
