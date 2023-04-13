#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
void	test();

int main()
{
	test();
	system("leaks AnimalFarm");
	return (0);
}

void	test()
{
	Animal *a = new Dog();
	Animal *b = new Cat();

	a->makeSound();
	b->makeSound();

	delete a;
	delete b;
}
