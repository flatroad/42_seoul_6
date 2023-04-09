#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:
		std::string	Name_;
		int			HitPoints_;
		int			EnergyPoints_;
		int			AttackDamage_;
	public:
		ClapTrap(std::string Name);
		~ClapTrap();
		ClapTrap(const ClapTrap& obj);
		ClapTrap &operator=(const ClapTrap& obj);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};		

#endif