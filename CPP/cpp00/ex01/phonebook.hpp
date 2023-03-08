#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact phoneList[8];
		int	check_;
	
	public:
		void	add();
		void	search();
		void	exit();
		void	set();
};

#endif
