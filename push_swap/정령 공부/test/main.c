#include "push_swap.h"

int main(int argc, char *argv[])
{
	stack A;
	int i;

	init(&A);
	i = argc - 1;

	while(i > 0)
	{
		printf("%s\n", argv[i]);
		push(&A, atoi(argv[i]));
		i--;
	}
	print_stack(&A);
}
