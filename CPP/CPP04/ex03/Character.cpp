#include "Character.hpp"

Character::Character()
{
  this->name_ = "none";
  for (int i = 0; i < 4; i++)
  {
    this->inventory[i] = NULL;
  }
}

Character::Character(const std::string& name)
{
  this->name_ = name;
  for (int i = 0; i < 4; i++)
  {
    this->inventory[i] = NULL;
  }
  for (int i = 0; i < 10; i++)
  {
    this->bag[i] = NULL;
  }
}

Character::Character(const Character& obj)
{
  operator=(obj);
}

Character &Character::operator=(const Character& obj)
{
  if (this != &obj)
  {
    this->name_ = obj.name_;
    for (int i = 0; i < 4; i++)
    {
      delete(this->inventory[i]);
      if (obj.inventory[i] != NULL)
      {
        this->inventory[i] = obj.inventory[i]->clone();
      }
      else
      {
        this->inventory[i] = NULL;
      }
    }
    for (int i = 0; i < 10; i++)
    {
      delete(this->bag[i]);
      if (obj.bag[i] != NULL)
      {
        this->bag[i] = obj.bag[i]->clone();
      }
      else
      {
        this->bag[i] = NULL;
      }
    }
  }
  return (*this);
}

Character::~Character()
{
  for (int i = 0; i < 4; i++)
  {
    if (this->inventory[i] != NULL)
    {
      delete(this->inventory[i]);
    }
  }
  for (int i = 0; i < 10; i++)
  {
    if (this->bag[i] != NULL)
    {
      delete(this->bag[i]);
    }
  }
  std::cout << "byebye" << this->getName() << std::endl;
}

const std::string& Character::getName() const
{
  return (this->name_);
}

void Character::equip(AMateria* m)
{
  if (m == NULL)
  {
    std::cout << "m이 null입니다" << std::endl;
    return ;
  }
  for (int i = 0; i < 4; i++)
  {
    if (this->inventory[i] == NULL)
    {
      std::cout << m->getType() << "슬롯 추가 " << i << std::endl;
      this->inventory[i] = m;
      return ;
    }
  }
  delete(m);
  std::cout << "빈 스킬슬롯이 없습니다." << std::endl;
}

void Character::unequip(int idx)
{
  if (idx < 0 || idx >= 4)
  {
    std::cout << idx << "   you so freak..." << std::endl;
    return ;
  }
  if (this->inventory[idx] != NULL)
  {
    for (int i = 0; i < 10; i++)
    {
      if (this->bag[i] == NULL)
      {
        std::cout << this->inventory[idx]->getType() << "을 가방에 수납합니다" << std::endl;
        this->bag[i] = this->inventory[idx];
        this->inventory[idx] = NULL;
        return ;
      }
    }
    std::cout << "가방이 가득 차서 못 들고 다녀요" << std::endl;
    return ;
  }
}

void Character::use(int idx, ICharacter& target)
{
  if (idx < 0 || idx >= 4)
  {
    std::cout << idx << "   you so freak..." << std::endl;
    return ;
  }
  if (this->inventory[idx] != NULL)
  {
    this->inventory[idx]->use(target);
    return ;
  }
  std::cout << idx << "번 스킬슬롯이 비었습니다." << std::endl;
}