#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
void	test();
void	test2();

int main()
{
	// test();
	test2();
	system("leaks AnimalFarm");
	return (0);
}

void	test()
{
	Animal *nimal[100];

	for (int i = 0; i < 50; i++)
	{
		nimal[i] = new Dog();
	}
	for (int i = 50; i < 100; i++)
	{
		nimal[i] = new Cat();
	}
	for (int i = 0; i < 100; i++)
	{
		delete nimal[i];
	}
}

void	test2()
{
	Dog *dog1 = new Dog();
	Dog *dog2 = new Dog();
	Dog *dog3;

	dog3 = dog2;
	
	dog1->ad_attr();
	dog2->ad_attr();
	dog3->ad_attr();

	delete dog1;
	delete dog2;
	delete dog3;
}

