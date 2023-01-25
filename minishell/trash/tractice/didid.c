#include <stdio.h>

int main()
{
	char *str;

	str = malloc(sizeof(char) * 2);
\
	printf("%s\n", str);
	printf("%c\n", *str + 2);

	return (0);
}