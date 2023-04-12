#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *attr_;
	public:
		Dog();
		~Dog();
		Dog(const Dog& obj);
		Dog &operator=(const Dog& obj);
		void	ad_attr();
		void	makeSound() const;
};		

#endif
