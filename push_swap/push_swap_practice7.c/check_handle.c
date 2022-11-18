#include "push_swap.h"

int	rec(int argc, int sup)
{
	if (argc % 3 != 0 || argc % 2 != 0)
		sup = 1;
	argc = (argc / 3) + sup;
	return (argc);
}

int	check_handle(int argc)
{
	int	sup;
	int	calc;

	sup = 0;
	calc = 1;
	while (argc > 3)
	{
		argc = rec(argc, sup);
		calc++;
	}
	return (calc);
}
