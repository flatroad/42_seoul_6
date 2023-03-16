#include "PhoneBook.hpp"
#include "CommonFN.hpp"

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
			PhoneBook::outSingleList(stoi(idx));
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
	while (idx != 8 || PhoneBook::phoneList[idx].searchFN().empty() != 1)
	{
		PhoneBook::outIdxList(idx);
		idx++;
	}
}

void	PhoneBook::outIdxList(int idx)
{
	std::cout << "|";
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

void	printf_list(std::string str)
{
	if (str.length() > 10)
	{
		for (int i = 0; i)
	}
}