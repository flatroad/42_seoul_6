#include <iostream>

class date 
{
	private:
		int year_;
		int month_;
		int day_;
	public:
		void showdate();

		date()
		{
			std::cout << "디폴트 생성자 호출" << std::endl;
			year_ = 2012;
			month_ = 7;
			day_ = 12;
		}
		date(int year, int month, int day)
		{
			std::cout << "인자 3개인 생성자 호출" << std::endl;
			year_ = year;
			month_ = month;
			day_ = day;
		}
};

void date::showdate()
{
	std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_ << " 일 입니다. " << std::endl;
}

int main()
{
	date day = date();
	date day2(2012, 10 , 31);

	day.showdate();
	day2.showdate();

	return (0);
}
