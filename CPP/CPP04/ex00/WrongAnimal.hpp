#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	private:
		std::string type_;
	public:
		void setType(std::string type);
		std::string const	getType() const;
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& obj);
		WrongAnimal &operator=(const WrongAnimal& obj);
		~WrongAnimal();
		void	makeSound() const;
};		

#endif

