#include "PhoneBook.hpp"
#include "CommonFN.hpp"

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
		std::cout << "if you all list just enter or you want particular phonebook\n, you write particular index : ";
		getline(std::cin, idx);
		idx = transToupper(idx);
		if (idx.empty() == 1)
			PhoneBook::outAllList();
		else if (idx.length() == 1 && idx.find_first_not_of("12345678") != std::string::npos)
			PhoneBook::outIdxList(stoi(idx));
		else if (idx.compare("EXIT") == 0)
			check = 0;
		else
			std::cout << "is not definite order, try again.." << std::endl;
	}
}

void	PhoneBook::outAllList()
{
	int	idx;
	std::string	str;

	idx = 0;
	while (idx != 8 || PhoneBook::phoneList[idx].outFN().empty() != 1)
	{
		PhoneBook::outIdxList(idx);
		idx++;
	}
}

void	PhoneBook::outIdxList(int idx)
{
	std::cout << "| ";
	PhoneBook::phoneList[idx].searchFN();
	std::cout << " | ";
	PhoneBook::phoneList[idx].searchLN();
	std::cout << " | ";
	PhoneBook::phoneList[idx].searchNN();
	std::cout << " | ";
	PhoneBook::phoneList[idx].searchPN();
	std::cout << " | ";
	PhoneBook::phoneList[idx].searchDS();
	std::cout << " |" << std::endl;
}
