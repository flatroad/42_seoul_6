#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
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

/*
	Name - 객체의 이름 #생성자에 인자로 넘겨준다.
	HitPoints - 체력
	EnergyPoints - 행동력
	AttackDamage - 공격력

	attack - 입력받음 target에게 자신이 공력력만큼의 데메지를 준다.
			단 해당 행동을 하면 행동력이 1감소한다.
	takeDamage - amount만큼 체력에서 감소됨.
	beRepaired - amount만큼 체력을 회복시킨다.
	 			단 해당 해동을 하면 행동력이 1감소한다.

	
	모든 구성원은 멤버함수에 대해 무슨일이 발생하였는지 메세지를 띄워야 한다.
	1. attack 함수는 ClapTrap의 이름과 타겟의 이름, 그리고 얼마만큼의 데미지를 입혔는지를 출력합니다.
	2. takeDamage 함수는 ClapTrap의 이름과 입은 데미지를 출력합니다.
	3. beRepaired 함수는 ClapTrap의 이름과 회복한 체력을 출력합니다.
	ex) a가 b에게 3만큼의 데메지를 주었다.

	생성자와 소멸자에 대한 메세지 출력도 할 것.
*/ 