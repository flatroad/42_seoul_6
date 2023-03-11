#include "cub3d.h"

int	map_validity(char **arr)
{
	int	checker[2];

	checker[0] = 0;
	checker[1] = 0;
	find_start_point(arr, checker);
	if (start_map_check(arr, checker) == 1)
		return (1);
}

void	find_start_point(char **arr, int checker[2])
{
	int	i;
	int	j;

	i = 0;
	while (arr[i] != NULL)
	{
		j = 0;
		if (arr[j] != 0)
		{
			if (arr[i][j] == 1)
			j++;
		}
		i++;
	}
}
