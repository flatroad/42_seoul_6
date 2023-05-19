#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	char path[1024];

	if(getcwd(path, 1024) == NULL) {
		fprintf(stderr, "current working directory get error: %s\n", strerror(errno));
		return -1;
	}
	printf("%s\n", path);

	return (0);
}