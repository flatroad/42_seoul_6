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

void	PhoneBook::search()
{
	int	check;
	std::string	idx;

	check = 1;
	while (check)
	{
		std::cout << "if you all list just enter or you want particular phonebook, you write particular index : ";
		getline(std::cin, idx);
		if (idx.empty() == 1)
		{
			PhoneBook::outAllList();
		}
	}
}

void	PhoneBook::outAllList()
{
	int	check;

	check = 1;
	while (check)
	{
		
	}
}

void	PhoneBook::set()
{
	check_ = 0;
}
