#ifndef MARINE_HPP
# define MARINE_HPP

#include <fstream>
#include <iostream>
#include <string>

class Marine
{
	private:
		int	hp_;
		int	coord_x_;
		int	coord_y_;
		int	damage_;
		bool	is_dead_;
	public:
		Marine();
		Marine(int x, int y);
		~Marine();
		int	attact();
		void	be_attacked(int damage_earn);
		void	move(int x, int y);
		void	show_status();
};

#endif
