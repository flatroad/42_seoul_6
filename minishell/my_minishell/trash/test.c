#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	make_str(char **s1, char *s2);

int main()
{
	char	*str;
	char	*s;

	s = malloc(3);

	s[0] = '1';
	s[1] = '2';
	s[2] = 0;

	make_str(&str, s);
	printf("%s\n", str);
	printf("%s\n", s);
	printf("%p\n", str);
	printf("%p\n", s);

	return (0);
}

void	make_str(char **s1, char *s2)
{
	*s1 = strdup(s2);
}