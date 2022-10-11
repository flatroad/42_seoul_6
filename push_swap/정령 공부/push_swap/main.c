#include "push_swap.h"
#include <xlocale.h>

int main(int argc, char *argv[])
{
	int i;

	i = 1;
	stack A;
	stack B;

	init(A);
	init(B);

	while (i < argc)
	{
		PUSH(&A, atoi(argv[i]));
		i++;
	}
	printstack(&A);

	return (0);
	
}