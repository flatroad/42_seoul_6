#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
void	test();
void	test2();

int main()
{
	test();
	test2();
	system("leaks AnimalFarm");
	return (0);
}

void	test()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
}

void	test2()
{
	const WrongAnimal *worngmeta = new WrongAnimal();
	const WrongAnimal *k = new WrongCat();
	std::cout << k->getType() << " " << std::endl;
	k->makeSound();
	worngmeta->makeSound();
	
	delete worngmeta;
	delete k;
}

