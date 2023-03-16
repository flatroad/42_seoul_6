#include "PhoneBook.hpp"

static std::string	transToupper(std::string str);

void	PhoneBook::search()
{
	int	check;
	std::string	idx;

	check = 1;
	while (check)
	{
		std::cout << "if you all list just enter or you want particular phonebook, you write particular index : ";
		getline(std::cin, idx);
		idx = transToupper(idx);
		if (idx.empty() == 1)
			PhoneBook::outAllList();
		else if (idx.length() == 1 && idx.find_first_not_of("12345678") == std::string::npos)
			PhoneBook::outSingleList(stoi(idx) - 1);
		else if (idx.compare("EXIT") == 0)
			check = 0;
		else
			std::cout << "is not definite order, try again.." << std::endl;
	}
}

void	PhoneBook::outSingleList(int i)
{
	std::cout << "first name : " << std::endl;
	std::cout << PhoneBook::phoneList[i].searchFN() << std::endl;
	std::cout << "last name : " << std::endl;
	std::cout << PhoneBook::phoneList[i].searchLN() << std::endl;
	std::cout << "nick name : " << std::endl;
	std::cout << PhoneBook::phoneList[i].searchNN() << std::endl;
	std::cout << "phone number : " << std::endl;
	std::cout << PhoneBook::phoneList[i].searchPN() << std::endl;
	std::cout << "darkest Secret : " << std::endl;
	std::cout << PhoneBook::phoneList[i].searchDS() << std::endl;
}

void	PhoneBook::outAllList()
{
	int	idx;
	std::string	str;

	idx = 0;
	if (PhoneBook::phoneList[0].searchFN().empty() == 1)
	{
		std::cout << "yet not have a PhoneBook" << std::endl;
		return ;
	}
	while (idx != 8 && PhoneBook::phoneList[idx].searchFN().empty() != 1)
	{
		PhoneBook::outIdxList(idx);
		idx++;
	}
	std::cout << "---------------------------------------------------------" << std::endl;
}

void	PhoneBook::outIdxList(int idx)
{
	std::cout << "---------------------------------------------------------" << std::endl;
	std::cout << "|";
	printfList(PhoneBook::phoneList[idx].searchFN());
	std::cout << "|";
	printfList(PhoneBook::phoneList[idx].searchLN());
	std::cout << "|";
	printfList(PhoneBook::phoneList[idx].searchNN());
	std::cout << "|";
	printfList(PhoneBook::phoneList[idx].searchPN());
	std::cout << "|";
	printfList(PhoneBook::phoneList[idx].searchDS());
	std::cout << "|" << std::endl;
}

void	PhoneBook::printfList(std::string str)
{
	std::string	sub;

	std::cout.width(10);
	if (str.length() > 10)
	{
		sub = str.substr(0, 9);
		std::cout << sub << ".";
		return ;
	}
	std::cout << std::right << str;
}

static std::string	transToupper(std::string str)
{
	for (int j = 0; str[j]; j++)
		str[j] = std::toupper(str[j]);
	return (str);
}
