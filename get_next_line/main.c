#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int main()
{
	int fd = open("./test.txt", O_RDONLY | O_CREAT, 0644);

	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", fd);
		printf("%s\n", get_next_line_bonus(fd));
	}
	return (0);
}