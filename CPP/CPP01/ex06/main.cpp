#include "Harl.hpp"

int	harl_function(Harl &harl);

int main()
{
	
	Harl harl;
	while (1)
	{
		std::cout << "you select order (DEBUG INFO WARNING ERROR FIN) FIN is Finish program" << std::endl;
		if(harl_function(harl))
			break ;
	}
	system("leaks Zombie");
	return (0);
}

int	harl_function(Harl &harl)
{
	std::string order;

	getline(std::cin, order);
	if (order.compare("DEBUG") && order.compare("INFO") && order.compare("WARNING") && order.compare("ERROR") && order.compare("FIN"))
	{
		std::cout << "is not order. retry" << std::endl;
		return (0);
	}
	else
	{
		if (order.compare("FIN") == 0)
			return (1);
		harl.complain(order);
	}
	return (0);
}