#include "libft.h"

int	**ft_mk_multi_arr(int a, int b)
{
	int i;
	int j;
	int	**arr;

	i = 0;
	arr = (int **)malloc(sizeof(int *) * a);
	while (i < a)
	{
		arr[i] = (int *)malloc(sizeof(int) * b);
		i++;
	}
	i = 0;
	while (i < a)
	{
		j = 0;
		while (j < b)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
	return (arr);
}