#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
  protected:
    std::string type_;
  
  public:
    AMateria();
    AMateria(const std::string& type);
    AMateria(const AMateria& obj);
    AMateria &operator=(const AMateria& obj);
    virtual ~AMateria();
    std::string const &getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif