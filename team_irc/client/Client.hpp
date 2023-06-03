#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <poll.h>
#include <sys/socket.h>
#include <netinet/in.h>


class Client {
	private:
		/*
			nick_name 중복체크
		*/
		std::string nick_name;
		std::string user_name;
		int cli_sock;
		struct sockaddr_in cli_addr;
		socklen_t cli_addr_size;
		std::string sub_memory;
	public:
	/*
		cli_sockaddr, cli_sockaddr_l은 main.cpp에 테스트용으로 있음
	*/
		bool pass_flag;
		int get_socket() const;
		void set_sub_memory(std::string str);
		struct sockaddr_in &get_cil_addr();
		socklen_t &get_cli_size();
		void set_socket(int cli_sock);
		void set_nick_name(std::string &nick_name);
		std::string get_nick_name() const;
		Client();
		~Client();
};

#endif
