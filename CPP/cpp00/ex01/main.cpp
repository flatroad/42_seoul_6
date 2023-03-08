#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string	transToupper(std::string s);

int	main()
{
	PhoneBook obj;
	obj.set();
	while (1)
	{
		std::string	order;
		getline(std::cin, order);
		order = transToupper(order);
		if (order.compare("ADD") == 0)
			obj.add();
		else if (order.compare("SEARCH") == 0)
			obj.search();
		else if (order.compare("EXIT") == 0)
			obj.exit();
	}
	return (0);
}

std::string	transToupper(std::string s)
{
	std::string	str = s;
	for (int j = 0; str[j]; j++)
		str[j] = std::toupper(str[j]);
	return (str);
}
