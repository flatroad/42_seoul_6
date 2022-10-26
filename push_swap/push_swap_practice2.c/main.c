#include "push_swap.h"

int		main(int argc, char **argv)
{
	char *order[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};

	if(push_swap(argc, argv, order) == FALSE)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
	system("leaks a.out");
}
