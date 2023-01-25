#include "stdio.h"

void	space(char **str);

int main()
{
	char *str;

	str = "1234";

	space(&str);

	printf("%s\n", str);
}

void	space(char **str)
{
	(*str)++;
	return ;
}
