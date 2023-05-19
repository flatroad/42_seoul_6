#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void test(char **str);

int main()
{
	char *str;
	char *st_str;
	int i;

	str = malloc(sizeof(char) * 10);
	i = 0;
	while (i < 10)
	{
		str[i] = i + 48;
		i++;
	}
	st_str = str;
	printf("%s\n", str);
	test(&str);
	printf("%s\n", st_str);
	free(st_str);
	free(st_str);

	return (0);
}

void test(char **str)
{
	(*str)++;
	(*str)++;

	printf("%s\n", *str);
}
