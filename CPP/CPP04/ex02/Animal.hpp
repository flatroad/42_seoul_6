#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	private:
		std::string type_;
	public:
		void setType(std::string type);
		std::string const	getType() const;
		Animal();
		Animal(std::string type);
		Animal(const Animal& obj);
		Animal &operator=(const Animal& obj);
		virtual ~Animal();
		virtual void	makeSound() const=0;
};		

#endif

