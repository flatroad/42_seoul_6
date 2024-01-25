#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
  for (int i = 0; i < 4; i++)
  {
    this->inventory[i] = NULL;
  }
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
  operator=(obj);
}

MateriaSource &MateriaSource::operator=(const MateriaSource& obj)
{
  if (this != &obj)
  {
    for (int i = 0; i < 4; i++)
    {
      delete(this->inventory[i]);
      if (obj.inventory[i])
      {
        this->inventory[i] = obj.inventory[i]->clone();
      }
      else
      {
        inventory[i] = NULL;
      }
    }
  }
  return (*this);
}

MateriaSource::~MateriaSource()
{
  for (int i = 0; i < 4; i++)
  {
    if (this->inventory[i] != NULL)
    {
      delete (this->inventory[i]);
    }
  }
  std::cout << "byebye MateriaSource" << std::endl;
}

void MateriaSource::learnMateria(AMateria *m)
{
  for (int i = 0; i < 4; i++)
  {
    if (this->inventory[i] == NULL)
    {
      this->inventory[i] = m->clone();
      return ;
    }
  }
  std::cout << " MateriaSource 빈 스킬슬롯이 없습니다." << std::endl;
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
  for (int i = 0; i < 4; i++)
  {
    if (this->inventory[i] != NULL)
    {
      if (this->inventory[i]->getType() == type)
      {
        return (this->inventory[i]->clone());
      }
    }
  }
  std::cout << "원하는 스킬이 없습니다." << std::endl;
  return (NULL);
}
