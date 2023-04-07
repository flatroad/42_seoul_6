#include "Marine.hpp"

Marine::Marine()
{
	std::cout << "marine born" << std::endl;
	hp_ = 50;
	coord_x_ = 0;
	coord_y_ = 0;
	damage_ = 5;
	is_dead_ = false;
}

Marine::Marine(int x, int y)
{
	std::cout << "marine born" << std::endl;
	hp_ = 50;
	coord_x_ = x;
	coord_y_ = y;
	damage_ = 5;
	is_dead_ = false;
}

Marine::~Marine()
{
	std::cout << "Marine die" << std::endl;
}

void Marine::move(int x, int y)
{
	coord_x_ = x;
	coord_y_ = y;
}

int Marine::attact()
{
	return (damage_);
}

void	Marine::be_attacked(int damage_earn)
{
	hp_ -= damage_earn;
	if (hp_ <= 0)
		is_dead_ = true;
}

void	Marine::show_status()
{
	std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x_ << " , " << coord_y_ << " ) "
            << std::endl;
  std::cout << " HP : " << hp_ << std::endl;
}
