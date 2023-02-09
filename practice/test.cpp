#include <iostream>

typedef struct animal
{
	char name[30];
	int	age;

	int health;
	int food;
	int clean;
} animal;

void create_animal(animal *ani)
{
	std::cout << "동물의 이름? : ";
	std::cin >> ani->name;

	std::cout << "동물의 나이? : ";
	std::cin >> ani->age;

	ani->health = 100;
	ani->clean = 100;
	ani->food = 100;
}

void play(animal *ani)
{
	ani->health += 10;
	ani->food -= 20;
	ani->clean -= 30;
}

void one_day_pass(animal *ani)
{
	ani->health += 10;
	ani->food -= 30;
	ani->food -= 20;
}

void show_stat(animal *ani)
{
	std::cout << ani->name << "의 상태" << std::endl;
	std::cout << "체력 : " << ani->health << std::endl;
	std::cout << "배부름 : " << ani->food << std::endl;
	std::cout << "청결 : " << ani->clean << std::endl;
}

int	main()
{
	animal *list[10];
	int animal_num = 0;

	for (;;)
	{
		std::cout << "1. 동물 추가하기 " << std::endl;
		std::cout << "2. 놀기 " << std::endl;
		std::cout << "3. 상태 보기 " << std::endl;
		
		int input;
		std::cin >> input;

		switch(input)
		{
			int play_with;
			case 1:
				list[animal_num] = new animal;
				create_animal(list[animal_num]);

				animal_num++;
				break ;
			case 2:
				std::cout << "누구랑 놀게? : ";
				std::cin >> play_with;

				if (play_with < animal_num) play(list[play_with]);

				break ;
			case 3:
				std::cout << "누구껄 보게 : ";
				std::cin >> play_with;

				if (play_with < animal_num) show_stat(l)
		}
}
