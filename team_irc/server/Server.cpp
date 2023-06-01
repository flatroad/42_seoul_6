#include "Server.hpp"
//stringstream
#include <sstream>

#include <cstdlib>

bool Server::is_num(char *s)
{
	int i = 0;
	if (s[i] == '-' || !std::isdigit(s[i++]))
		return (false);
	while (s[i] && std::isdigit(s[i]))
		i++;
	if (s[i] == '\0')
		return (true);
	return (false);
}

Server::Server(char *srv_port, char *passwd) : passwd(passwd)
{
	try
	{
		if(this->is_num(srv_port) == false)
			throw (1);
	}
	catch(...)
	{
		std::cerr << "is not num" << std::endl;
		throw (10);
	}
	std::stringstream ss(srv_port);
	ss >> this->srv_port;
	try
	{
		std::string str = passwd;
		if (str.empty() == 0)
			throw("empty passwd");
		int len = str.length();
		if (!(len > 5 && len < 11))
			throw("len_worng passwd");
	}
	catch(char *str)
	{
		std::cerr << str << std::endl;
		throw (10);
	}
}

void Server::parse_map_init()
{
	this->parse_map["PING"] = 1;
	this->parse_map["PASS"] = 2;
	this->parse_map["NICK"] = 3;
	this->parse_map["NAME"] = 4;
	this->parse_map["PRIVMSG"] = 5;
	this->parse_map["TOPIC"] = 6;
	this->parse_map["JOIN"] = 7;
	this->parse_map["MODE"] = 8;
	this->parse_map["KICK"] = 9;
}

void Server::init()
{
	this->srv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (srv_sock == -1)
	{
		std::cerr << "socket() error" << std::endl;
		throw (errno);
	}
	this->serv_addr.sin_family = AF_INET;
	this->serv_addr.sin_addr.s_addr = INADDR_ANY;
	this->serv_addr.sin_port = htons(this->srv_port);

	if (bind(this->srv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
	{
		std::cerr << "bind() error" << std::endl;
		throw (errno);
	}
	if (listen(this->srv_sock, 5) == -1)
	{
		std::cerr << "listen() error" << std::endl;
		throw (errno);
	}
}

void Server::start()
{
	// 여기서 accept 진행.
	// 여기서 while {poll()받을것}
	// 여기서 부터는 오류에 따라 종료 진행 결정.
}

int Server::get_cmd(std::string s) {	return (this->parse_map[s]); }

char* Server::get_passwd() const { return (this->passwd); }

Client* Server::find_cli_with_nick_name(std::string &nick_name)
{
	std::set<Client *>::iterator it = this->cli_set.begin();
	for (; it != cli_set.end(); it++)
	{
		if(!nick_name.compare((*it)->get_nick_name()))
		{
			return ((*it));
		}
	}
	return (NULL);
}

Channel* Server::get_channel(std::string &channel_name)
{
	std::set<Channel *>::iterator it = this->ch_set.begin();
	for (; it != this->ch_set.end(); ++it)
	{
		if ((*it)->get_ch_name() == channel_name)
			return ((*it));
	}
	return (NULL);
}

Server::~Server(){}