#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line.h"

void gnl(int fd, char const *expectedReturn)
{
	char *gnlReturn = get_next_line(fd);
	if (expectedReturn == NULL)
	{
		if (gnlReturn == NULL)
			printf("\nNULL");
	}
	else
		if (!strcmp(gnlReturn, expectedReturn))
			printf("%s", expectedReturn);
	free(gnlReturn);
}

int main(void)
{
	int fd;
	fd = open("/home/user/get_next_line/test.txt", O_RDWR);
	if (fd == -1)
	{
		printf("fail");
		return (0);
	}
	gnl(fd, "01234567890123456789012345678901234567890\n");
	gnl(fd, "987654321098765432109876543210987654321098\n");
	gnl(fd, "0123456789012345678901234567890123456789012\n");
	gnl(fd, "987654321098765432109876543210987654321098\n");
	gnl(fd, "01234567890123456789012345678901234567890");
	gnl(fd, NULL);
	return (0);
}