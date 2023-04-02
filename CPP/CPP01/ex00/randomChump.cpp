#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie rd_obj(name);
	rd_obj.announce();
}
