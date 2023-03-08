#include "PhoneBook.hpp"

void	PhoneBook::add()
{
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

	check_ = check_ % 8;
	std::cout << check_ << "list" << std::endl;
	phoneList[check_].insertFN(firstName);
	phoneList[check_].insertLN(lastName);
	phoneList[check_].insertNN(nickName);
	phoneList[check_].insertPN(phoneNumber);
	phoneList[check_].insertDS(darkestSecret);
	check_++;
}

void	PhoneBook::test()
{
	check_ = 0;
}