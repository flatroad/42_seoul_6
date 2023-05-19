#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	**make_arr(int y, int x)
{
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * y);
	for (int i = 0; i < y; i++)
	{
		arr[i] = (char *)malloc(sizeof(char) * x);
		for (int j = 0; j < x; j++)
		{
			arr[i][j] = '0';
		}
	}
	return (arr);
}

void	draw_point(float m, float k, int b, char ** arr)
{
	int	x;

	if (k + m + 0.5 < (int)(k + 1) / 1)
		x = k / 1;
	else
		x = (int)(k + 1) / 1;
	printf("%d\n", x);

	arr[x][b] = '1';
}

void	dda(int a, int b, int f, int g, char **arr)
{
	float	m;
	float	k;

	arr[a][b] = '1';
	arr[f][g] = '1';

	m = (float)(f - a) / (float)(g - b);
	k = (float)a;
	while (b < g)
	{
		draw_point(m, k, b, arr);
		k = k + m;
		b++;
	}
}

void	print_arr(char **arr, int y)
{
	for (int i = 0; i < y; i++)
		printf("%s\n", arr[i]);
}

int	main()
{
	char	**arr;

	int y = 100;
	int x = 100;
	arr = make_arr(y, x);
	dda(3, 3, 60, 68, arr);
	print_arr(arr, y);
	return (0);
}