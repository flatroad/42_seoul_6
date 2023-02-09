#include <iostream>

class date
{
	private:
		int	year_;
		int	month_;
		int	day_;
	public:
		void addday(int inc);
		void addmonth(int inc);
		void addyear(int inc);
		int getcurrecnt(int year, int month);
		void showdate();
	
	date(int year, int month, int day)
	{
		year_ = year;
		month_ = month;
		day_ = day;
	}
};

int date::getcurrecnt(int year, int month)
{
	static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month != 2)
	{
		return (month_day[month - 1]);
	}
	else if (year % 4 == 0 && year % 100 != 0)
	{
		return 29;
	}
	else
		return 28;
}

void date::addday(int inc)
{
	while (true)
	{
		int current_month = getcurrecnt(year_, month_);
		if (day_ + inc <= current_month)
		{
			day_ += inc;
			return ;
		}
		else{
			inc -= (current_month - day_ + 1);
			day_ = 1;
			addmonth(1);
		}
	}
}

void date::addmonth(int inc)
{
	addyear((inc + month_ - 1) / 12);
	month_ = month_ + inc % 12;
	month_ = (month_ == 12 ? 12 : month_ % 12);
}

void date::addyear(int inc)
{
	year_ += inc;
}

void date::showdate()
{
	std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_ << " 일 입니다." << std::endl;
}

int main()
{
	date day(2011, 3, 1);
	day.showdate();

	day.addday(30);
	day.showdate();

	day.addday(2000);
	day.showdate();

	day.addday(29);
	day.showdate();

	day.addday(2500);
	day.showdate();

	day.addday(30);
	day.showdate();

	return (0);
}
