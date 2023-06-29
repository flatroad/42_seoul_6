#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int main()
{
	int fd1 = open("./test1.txt", O_WRONLY | O_CREAT , 0644);
	int fd2 = open("./test2.txt", O_WRONLY | O_CREAT , 0644);

	printf("%d ,%d\n", fd1, fd2);
	for (int i = 0; i < 5; i++)
	{
		char *str;

		str = get_next_line_bonus(fd1);
		printf("%s\n", str);
		free(str);
		str = get_next_line_bonus(fd2);
		printf("%s\n", str);
		free(str);
	}
}