#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string firstName_;
		std::string lastName_;
		std::string nickName_;
		std::string phoneNumber_;
		std::string darkestSecret_;
	public:
		void		insertFN(std::string firstName);
		void		insertLN(std::string lastName);
		void		insertNN(std::string nickName);
		void		insertPN(std::string phoneNumber);
		void		insertDS(std::string darkestSecret);
		void		searchFN();
		void		searchLN();
		void		searchNN();
		void		searchPN();
		void		searchDS();
		std::string	outFN();
};

#endif