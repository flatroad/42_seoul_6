#include " BitcoinExchange.hpp"

BERICH::BERICH(char *str):input_file_(str),data_base_(Database){}

BERICH::~BERICH()
{
	std::cout << "exit" << std::endl;
}

void	BERICH::checkOpenFile()
{
	if (this->input_file_.is_open() == False)
		throw ("worng inputfile");
	if (this->data_base_.is_open() == False)
		throw ("worng data_base_");
}

std::ifstream	&BERICH::getInputFile()
{
	return (this->input_file_);
}

std::ifstream	&BERICH::getDateBase()
{
	return (this->data_base_);
}

bool	BERICH::checkYear(std::string str)
{
	std::istringstream	str_num(str);
	int	year;
	str_num >> year;
	if (year < 2001)
		return (False);
	if (year > 2099)
		return (False);
	if (str_num.fail() == True)
		return (False);
	if (str_num.eof() == False)
		return (False);
	return (True);
}

bool	BERICH::checkMonth(std::string str)
{
	std::istringstream	str_num(str);
	int	month;
	str_num >> month;
	if (month > 12)
		return (False);
	if (month < 0)
		return (False);
	if (str_num.fail() == True)
		return (False);
	if (str_num.eof() == False)
		return (False);
	return (True);
}

bool	BERICH::checkDay(std::string str, std::string s_year, std::string s_month)
{
	std::istringstream	str_year(s_year);
	int year;
	str_year >> year;
	std::istringstream	str_month(s_month);
	int month;
	str_month >> month;
	std::istringstream	str_day(str);
	int	day;
	str_day >> day;
	if (str_day.fail() == True)
		return (False);
	if (str_day.eof() == False)
		return (False);
	if (day < 1)
		return (False);
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day > 31)
			return (False);
	}
	else if (month == 2)
	{
		if (year % 4 != 0)
		{
			if (day > 29)
				return (False);
		}
		else
		{
			if (day > 28)
				return (False);
		}
	}
	else
	{
		if (day > 30)
			return (False);
	}
	return (True);
}

/// -------------------------------------------- database -------------------------------------------------------

void	BERICH::checkProperDatabase(std::ifstream &file)
{
	queue				que;
	std::string			one_line;

	getline(file, one_line);
	if (firstcheckProperDatabase(one_line) == False)
		throw ("database checkProperDatabase wrong");
	while (getline(file, one_line))
	{
		que = this->devideDatebaseDateValue(one_line);
		int		date = this->devideDatebaseDate(que.front());
		que.pop();
		double value = this->devideDatebaseValue(que.front());
		que.pop();
		this->data_[date] = value;
	}
}

double BERICH::devideDatebaseValue(std::string str)
{
	std::istringstream	str_num(str);
	double	value;
	str_num >> value;
	if (value < 0)
		throw ("database value is fail");
	if (value > 1000000000.0)
		throw ("database value is fail");
	if (str_num.fail() == True)
		throw ("database value is fail");
	if (str_num.eof() == False)
		throw ("database value is fail");
	return (value);
}

int		BERICH::devideDatebaseDate(std::string str)
{
	std::istringstream	date(str);
	std::string			memoyear;
	std::string			memomonth;
	std::string			memoday;
	int					num;

	std::getline(date, memoyear, '-');
	if (this->checkYear(memoyear) == False)
		throw ("datebase year is fail");
	std::getline(date, memomonth, '-');
	if (this->checkMonth(memomonth) == False)
		throw ("datebase month is fail");
	std::getline(date, memoday, '-');
	if (this->checkDay(memoday, memoyear, memomonth) == False)
		throw ("datebase day is fail");
	memoyear.append(memomonth);
	memoyear.append(memoday);
	std::istringstream answer(memoyear);
	answer >> num;
	return (num);
}

queue	BERICH::devideDatebaseDateValue(std::string str)
{
	queue				que;
	std::istringstream	datevalue(str);
	std::string 		memo;

	while(std::getline(datevalue, memo, ','))
	{
		memo.erase(remove(memo.begin(), memo.end(), ' '), memo.end());
		que.push(memo);
	}
	if (que.size() != 2)
		throw ("lack -> database date or value");
	return (que);
}

bool	BERICH::firstcheckProperDatabase(std::string str)
{
	std::istringstream	origin(str);
	std::string 		memo;
	queue				que;

	while(std::getline(origin, memo, ','))
	{
		memo.erase(remove(memo.begin(), memo.end(), ' '), memo.end());
		que.push(memo);
	}
	if (que.size() != 2)
		return (False);
	if (que.front().compare("date"))
		return (False);
	que.pop();
	if (que.front().compare("exchange_rate"))
		return (False);
	que.pop();
	if (que.empty())
		return (True);
	return (False);
}

/// -------------------------------------------- inputfile -------------------------------------------------------


void	BERICH::checkProperInputfile(std::ifstream &file)
{
	std::string	one_line;

	getline(file, one_line);
	if (this->firstcheckProperInputfile(one_line) == False)
		throw ("inputfile checkProperDatabase wrong");
	while (getline(file, one_line))
	{
		try
		{
			queue	que;
			que = this->devideInputfileDateValue(one_line);
			int		date = this->devideDateInputfile(que.front());
			que.pop();
			double value = this->devideInputfileValue(que.front());
			que.pop();
			this->btcPrint(date, value);
		}
		catch (const char *str)
		{
			std::cerr << str << std::endl;
		}
	}
}

void	BERICH::btcPrint(int date, double value)
{
	std::map<int, double>::iterator	it;

	it = this->data_.find(date);
	if (it == this->data_.end())
	{
		it = this->data_.lower_bound(date);
		if (it == this->data_.begin())
			throw ("no find data, is too old date");
		else
		{
			--it;
			std::cout << (*it).first / 10000 << "-" << ((*it).first % 10000) / 100 << "-" << (*it).first % 100;
			std::cout << " => " << value << " = " << value * (*it).second << std::endl;
			return ;
		}
	}
	std::cout << (*it).first / 10000 << "-" << ((*it).first % 10000) / 100 << "-" << (*it).first % 100;
	std::cout << " => " << value << " = " << value * (*it).second << std::endl;
}

bool	BERICH::firstcheckProperInputfile(std::string str)
{
	std::istringstream	origin(str);
	std::string 		memo;
	queue				que;

	while(std::getline(origin, memo, '|'))
	{
		memo.erase(remove(memo.begin(), memo.end(), ' '), memo.end());
		que.push(memo);
	}
	if (que.size() != 2)
		return (False);
	if (que.front().compare("date"))
		return (False);
	que.pop();
	if (que.front().compare("value"))
		return (False);
	que.pop();
	if (que.empty())
		return (True);
	return (False);
}

double BERICH::devideInputfileValue(std::string str)
{
	std::istringstream	str_num(str);
	double	value;
	str_num >> value;
	if (value < 0)
		throw ("Error: not a positive number.");
	if (value > 1000.0)
		throw ("Error: too large a number.");
	if (str_num.fail() == True)
		throw ("inputfile value is fail");
	if (str_num.eof() == False)
		throw ("inputfile value is fail");
	return (value);
}

int		BERICH::devideDateInputfile(std::string str)
{
	std::istringstream	date(str);
	std::string			memoyear;
	std::string			memomonth;
	std::string			memoday;
	int					num;

	std::getline(date, memoyear, '-');
	if (this->checkYear(memoyear) == False)
		throw ("inputfile year is fail");
	std::getline(date, memomonth, '-');
	if (this->checkMonth(memomonth) == False)
		throw ("inputfile month is fail");
	std::getline(date, memoday, '-');
	if (this->checkDay(memoday, memoyear, memomonth) == False)
		throw ("inputfile day is fail");
	memoyear.append(memomonth);
	memoyear.append(memoday);
	std::istringstream answer(memoyear);
	answer >> num;
	return (num);
}

queue	BERICH::devideInputfileDateValue(std::string str)
{
	queue				que;
	std::istringstream	datevalue(str);
	std::string 		memo;

	while(std::getline(datevalue, memo, '|'))
	{
		memo.erase(remove(memo.begin(), memo.end(), ' '), memo.end());
		que.push(memo);
	}
	if (que.size() != 2)
		throw (str.insert(0, "Error: bad input ").c_str());
	return (que);
}