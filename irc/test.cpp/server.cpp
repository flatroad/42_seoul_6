#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string>

#define CLNT_MAX 10

int clnt_socks[CLNT_MAX];

int main(int argc, char  **argv)
{
	int sev_sock;
	struct sockaddr_ip serv_addr;
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	if(bind(serv_sock, &serv_addr, sizeof(serv_addr)) == -1)
	{
		printf("bind error\n");
	}
	if 
}