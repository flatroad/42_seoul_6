#include " BitcoinExchange.hpp"

BERICH::BERICH(char *str):input_file_(str),data_base_(Database){}

BERICH::~BERICH()
{
	std::cout << "exit" << std::endl;
}

static std::string	chooseIt(char a)
{
	if (a == ',')
		return ("datadase ");
	return ("inputfile ");
}

void	BERICH::checkOpenFile()
{
	if (this->input_file_.is_open() == False)
		throw ("worng inputfile");
	if (this->data_base_.is_open() == False)
		throw ("worng data_base_");
}



void	BERICH::checkProperData(char a, std::ifstream &file)
{
	std::string	one_line;
	getline(file, one_line);
	if (firstcheckProperData(one_line, a) == False)
		throw ((chooseIt(a) + "checkProperData wrong").c_str());
	while (getline(file, one_line))
	{
		int	date = this
	}
}

int		BERICH::checkProperData(std::string str, char a)
{
	queue	que;
	que = this.devideDateValue(str)
}

bool	BERICH::firstcheckProperData(std::string str, char a)
{
	std::istringstream	origin(str);
	std::string 		memo;
	queue				que;
	const char	*value = "value";
	if (a == ',')
		value = "exchange_rate";
	
	while(std::getline(origin, memo, a))
	{
		memo.erase(remove(memo.begin(), memo.end(), ' '), memo.end());
		que.push(memo);
	}
	if (que.front().compare("date"))
		return (False);
	que.pop();
	if (que.front().compare(value))
		return (False);
	que.pop();
	if (que.empty())
		return (True);
	return (False);
}

std::ifstream	&BERICH::getInputFile()
{
	return (this->input_file_);
}

std::ifstream	&BERICH::getDateBase()
{
	return (this->data_base_);
}