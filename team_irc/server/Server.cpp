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
		throw ("socket() error");
	this->serv_addr.sin_family = AF_INET;
	this->serv_addr.sin_addr.s_addr = INADDR_ANY;
	this->serv_addr.sin_port = htons(this->srv_port);

	if (bind(this->srv_sock, reinterpret_cast<sockaddr*>(&serv_addr), sizeof(serv_addr)) == -1)
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

void Server::make_event_window()
{
	fds[0].fd = this->srv_sock;
	fds[0].events = POLLIN;
	for (int i = 1; i < MAXCLIENT + 1; ++i)
		fds[i].fd = -1;
}

void Server::accept_client()
{
	Client *client = new Client;
	client->set_socket(accept(this->srv_sock, \
	reinterpret_cast<sockaddr*>(&client->get_cil_addr()), &(client->get_cli_size())));
	if (client->get_socket() == -1)
	{
		delete client;
		throw(1);
	}
	this->find_vacant_fds().fd = client->get_socket();
}

struct pollfd &Server::find_vacant_fds()
{
	for(int i = 1; i < MAXCLIENT + 1; i++)
	{
		if (this->fds[i].revents & POLLIN)
		{
			this->fds[i].events = POLLIN | POLLERR | POLLHUP;
			return (this->fds[i]);
		}
	}
}

void Server::execute()
{
	this->make_event_window();
	while (1)
	{
		int check = poll(fds, MAXCLIENT + 1, -1);
		if (check == -1)
			throw("poll() error");
		if (fds[0].revents & POLLIN)
		{
			accept_client();
			continue ;
		}
		for (int i = 1; i < MAXCLIENT + 1; i++)
		{
			if (fds[i].fd == -1)
				continue ;
			if (fds[i].revents & POLLIN)
			{
				message_receive(fds[i]);
				break ;
			}
			if (fds[i].revents & POLLHUP || fds[i].revents & POLLERR)
			{
				erase_clinet(fds[i]);
				break ;
			}      
		}
	}
}

std::string Server::message_receive(pollfd &fds)
{
	std::string message;
	std::string sv_message;
	Client client;
	char buffer[1024];
	int message_size = 0;
	int idx = -1;

	while (idx == -1)
	{
		message_size = recv(fds.fd, buffer, 1024, 0);
		if (message_size == -1)
			throw (1);
		message.append(buffer);
		idx = message.find("\r\n");
	}
	this->find_client(fds.fd)->set_sub_memory(message.substr(idx + 2));
	return (message.substr(0, idx + 2));
}

Client *Server::find_client(int fd)
{
	std::set<Client *>::iterator it = this->cli_set.begin();
	for (; it != cli_set.end(); it++)
	{
		if( (*it)->get_socket() == fd)
		{
			return ((*it));
		}
	}
	return (NULL);
}

void Server::erase_clinet(pollfd &fds)
{
	Client *client;
	client = this->find_client(fds.fd);
	close(client->get_socket());
	/*
		Todo
		클라이언트 연쇄제거
	*/
	// delete client;
	fds.fd = -1;
	fds.events = 0;
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