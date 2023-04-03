#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string	att_type_;
	public:
		Weapon(std::string att_type);
		~Weapon();
		const std::string	&getType() const;
		void	setType(std::string att_type);
};

#endif
