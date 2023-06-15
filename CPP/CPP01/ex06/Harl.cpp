#include "Harl.hpp"

Harl::Harl()
{
	ptrFunc[2] = &Harl::debug;
	ptrFunc[0] = &Harl::info;
	ptrFunc[1] = &Harl::warning;
	ptrFunc[3] = &Harl::error;
}

Harl::~Harl()
{
	std::cout << "ex05 finish" << std::endl;
}

void Harl::debug( void )
{
	std::cout << "debug : " << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "info : " << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "warning : " << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "error : " << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
	int a = level[0];

	(this->*ptrFunc[a % 13 % 7 - 1])();
}


void Harl::complain(std::string level){
	int i = 0;
	for (; i < FUNC_SIZE; i++){
		if (!level.compare(cmd[i])){
			break;
		}
	}
	switch (i)
	{
	case (DEBUG):
		(this->*f[DEBUG])();
	case (INFO):
		(this->*f[INFO])();
	case (WARNING):
		(this->*f[WARNING])();
	case (ERROR):
		(this->*f[ERROR])();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}