#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

void test0();
void test1();
void test2();

int main()
{
  test0();
  // test1();
  // test2();
  system("leaks Interface");
  return 0;
}


void test0()
{
  IMateriaSource* src = new MateriaSource();
  AMateria* tmp1 = new Ice();
  AMateria* tmp2 = new Cure();
  src->learnMateria(tmp1);
  src->learnMateria(tmp2);
  ICharacter* me = new Character("test0");
  me->equip(src->createMateria("ice"));
  me->equip(src->createMateria("ice"));
  me->equip(src->createMateria("ice"));
  me->equip(src->createMateria("ice"));
  // 빈슬롯이 없습니다.
  me->equip(src->createMateria("ice"));
  me->equip(src->createMateria("ice"));
  // 말도 안돼는 숫자
  me->unequip(6);
  // 가방 수납
  me->unequip(3);
  me->unequip(2);
  ICharacter* bob = new Character("bob");
  me->use(2, *bob);
  me->use(0, *bob);
  delete me;
  delete bob;
  delete src;
  delete tmp1;
  delete tmp2;
}
// leak 발생 테스트
void test1() 
{
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter* me = new Character("test1");
  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  delete bob;
  delete me;
  delete src;
}

// leak 발생 테스트
void test2()
{
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter* me = new Character("test2");
  AMateria* tmp;
  tmp = src->createMateria("none");
  std::cout << "testtest" << std::endl;
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  delete bob;
  delete me;
  delete src;
}