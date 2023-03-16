#include <stdio.h>

int main()
{
	int a;
	char *b;
	
	a = 48;

	b = (char *)&a;
	printf("%p\n", b);
	printf("%d\n", a);

	a = 49;
	printf("%p\n", b);
	printf("%p\n", &a);
}