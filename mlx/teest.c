#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main()
{
	int x = 32;
	int j = 0;

	if (x % 10 > 0)
		j = x / 10 + 1;

	printf("%d\n", j);
	return (0);
}