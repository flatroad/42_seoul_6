#include <stdio.h>
#include <stdlib.h>

char	*push_swap(int argv, char *argc[])
{
	return (0);
}

int	check_nbr(int argc, int stack_a[], char *argv)
{
	return (0);
}

int	main(int argc, char *argv[])
{
	int stack_a = malloc(argc * 4);
	int stack_b = malloc(argc * 4);
	if (stack_a == NULL || stack_b == NULL)
		return ("NULL");
	if (check_nbr(argc, stack_a, argv) == 0)
		return ("NULL");
	devide(stack_b, stack_a);

	push_swap(stack_a, stack_b, 1);

	return (0);
}