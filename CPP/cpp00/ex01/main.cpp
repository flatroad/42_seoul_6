#include "PhoneBook.hpp"
#include "Contact.hpp"

static std::string	transToupper(std::string str);

int	main()
{
	PhoneBook obj;
	std::string	order;

	obj.set();
	while (1)
	{
		std::cout << "ADD, SEARCH and EXIT, what you want?" << std::endl;
		getline(std::cin, order);
		order = transToupper(order);
		if (order.compare("ADD") == 0)
			obj.add();
		else if (order.compare("SEARCH") == 0)
			obj.search();
		else if (order.compare("EXIT") == 0)
		{
			if (obj.exit() == 1)
				break ;
		}
		else
			std::cout << "worng order.." << std::endl;
	}
	system("leaks PhoneBook");
	return (0);
}

static std::string	transToupper(std::string str)
{
	for (int j = 0; str[j]; j++)
		str[j] = std::toupper(str[j]);
	return (str);
}
