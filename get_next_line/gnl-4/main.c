#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int	fd;
	char *flag;

	fd = open ("./text.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("디스크립터가 실패했습니다.");
		return (0);
	}
	while (flag != 0)
	{
		flag = get_next_line(fd);
		printf("%s", flag);
	}
	
	return (0);
}
