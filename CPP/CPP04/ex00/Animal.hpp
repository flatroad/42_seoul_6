#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	private:
		std::string type_;
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& obj);
		Animal &operator=(const Animal& obj);
		~Animal();
		void	makeSound();
};		

#endif

