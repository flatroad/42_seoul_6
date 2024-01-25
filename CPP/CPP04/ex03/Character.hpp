#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <vector>

class AMateria;

class Character : public ICharacter
{
  private:
    std::string name_;
    AMateria *inventory[4];
    AMateria *bag[10];

  public:
    Character();
    Character(const std::string& name);
    Character(const Character& obj);
    Character &operator=(const Character& obj);
    virtual ~Character();
    virtual const std::string& getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
};

#endif