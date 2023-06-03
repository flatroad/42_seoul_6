#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <Channel.hpp>
#include <string>
#include <set>
#include <map>

// 테스트용
#include <vector>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXCLIENT 20

class Server {
	private:
		int srv_sock;
		int srv_port;
		char *passwd;
		struct pollfd fds[MAXCLIENT + 1];
		struct sockaddr_in serv_addr;
		std::set<Channel *> ch_set;
		std::set<Client *> cli_set;
		std::map<std::string, int> parse_map;
		void accept_client();
		void erase_clinet();
	public:
		std::vector<Client *>cli_vector;
		Server(char *srv_port, char *passwd);
		void parse_map_init();
		void init();
		void make_event_window();
		void execute();
		Client *find_client(int fd);
		std::string message_receive(pollfd &fds);
		struct pollfd &Server::find_vacant_fds();
		bool is_num(char *s);
		void set_socket(int socker_fd);
		int get_socket() const;
		Channel* get_channel(std::string &channel_name);
		void set_channel(std::string &channel_name);
		int get_cmd(std::string s);
		char* get_passwd() const;
		Client* find_cli_with_nick_name(std::string &nick_name);
		~Server();

};

#endif
