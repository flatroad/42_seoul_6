#include "Contact.hpp"

void	Contact::insertFN(std::string firstName)
{
	int	check;

	check = 1;
	while (check)
	{
		std::cout << "firstName : ";
		getline(std::cin, firstName);
		if (firstName.empty() == 1)
		{
			std::cout << "firstName is empty.. try again!" << std::endl;
			continue ;
		}
		check = 0;
		for (int i = 0; i < firstName[i]; i++)
		{
			if (!(std::isalpha(firstName[i])))
			{
				std::cout << "is not string.. try again!" << std::endl;
				check = 1;
				break ;
			}
		}
	}
	firstName_ = firstName;
}

void	Contact::insertLN(std::string lastName)
{
	int	check;

	check = 1;
	while (check)
	{
		std::cout << "lastName : ";
		getline(std::cin, lastName);
		if (lastName.empty() == 1)
		{
			std::cout << "lastName is empty.. try again!" << std::endl;
			continue ;
		}
		check = 0;
		for (int i = 0; i < lastName[i]; i++)
		{
			if (!(std::isalpha(lastName[i])))
			{
				std::cout << "is not string.. try again!" << std::endl;
				check = 1;
				break ;
			}
		}
	}
	lastName_ = lastName;
}

void	Contact::insertNN(std::string nickName)
{
	int	check;

	check = 1;
	while (check)
	{
		std::cout << "nickName : ";
		getline(std::cin, nickName);
		if (nickName.empty() == 1)
		{
			std::cout << "nickName is empty.. try again!" << std::endl;
			continue ;
		}
		check = 0;
		for (int i = 0; i < nickName[i]; i++)
		{
			if (!(std::isalpha(nickName[i])))
			{
				std::cout << "is not string.. try again!" << std::endl;
				check = 1;
				break ;
			}
		}
	}
	nickName_ = nickName;
}

void	Contact::insertPN(std::string phoneNumber)
{
	while (1)
	{
		std::cout << "phoneNumber : ";
		getline(std::cin, phoneNumber);
		if (phoneNumber.empty() == 1)
		{
			std::cout << "phoneNumber is empty.. try again!" << std::endl;
			continue ;
		}
		if (!(phoneNumber.find_first_not_of("0123456789") == std::string::npos))
		{
			std::cout << "is not number.. try again!" << std::endl;
			continue ;
		}
		if (phoneNumber.length() != 11)
		{
			std::cout << "is not phoneNumber.. try again!" << std::endl;
			continue ;
		}
		break ;
	}
	phoneNumber_ = phoneNumber;
}

void	Contact::insertDS(std::string darkestSecret)
{
	int	check;

	check = 1;
	while (check)
	{
		std::cout << "darkestSecret : ";
		getline(std::cin, darkestSecret);
		if (darkestSecret.empty() == 1)
		{
			std::cout << "darkestSecret is empty.. try again!" << std::endl;
			continue ;
		}
		check = 0;
		for (int i = 0; i < darkestSecret[i]; i++)
		{
			if (!(std::isalpha(darkestSecret[i])))
			{
				std::cout << "is not string.. try again!" << std::endl;
				check = 1;
				break ;
			}
		}
	}
	darkestSecret_ = darkestSecret;
}
