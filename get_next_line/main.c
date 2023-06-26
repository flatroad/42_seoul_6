#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"
#include "get_next_line.h"

int main()
{
	int fd = open("./test.txt", O_RDONLY | O_CREAT, 0644);
	int fd2 = open("./test2.txt", O_RDONLY | O_CREAT, 0644);

	for (int i = 0; i < 3; i++)
	{
		char *str;
		printf("%d, %d\n", fd, fd2);
		str = get_next_line_bonus(fd);
		printf("%s\n", str);
		free(str);
		str = get_next_line_bonus(fd2);
		printf("%s\n", str);
		free(str);
	}
	return (0);
}