#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact PhoneBook[8];
		int	check = 0;
	public:
		void	ADD();
		void	SEARCH();
		void	EXIT();
};

#endif
