#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

typedef struct	s_map
{
	int		hei;
	int		wid;
	char	ground;
}	t_map;

typedef struct	s_obj
{
	char	type;
	float	x;
	float	y;
	float	radius;
	char	shape;
}	t_obj;

void	paint_ground(char *area, int max, char c);
int		read_map(FILE *file, t_map *map);
int		error_handle(int cas);
void	write_map(char *area, t_map map);
int		start_obj(t_map map, char *area, FILE *file);
int		check_obj(t_obj obj);
void	paint_obj(char *area, t_obj obj, t_map map);
int		check_flag(float x, float y, t_obj obj);

int main(int argc, char **argv)
{
	t_map	map;
	char	*area;
	FILE	*file;

	if (argc != 2)
		return (error_handle(0));
	file = fopen(argv[1], "r");
	if (file == 0)
		return (error_handle(1));
	if (read_map(file, &map) == 1)
		return (error_handle(1));
	area = (char *)malloc(sizeof(char) * (map.hei * map.wid));
	if (area == NULL)
		return (error_handle(1));
	paint_ground(area, (map.hei * map.wid), map.ground);
	if(start_obj(map, area, file) == 1)
	{
		free(area);
		return (error_handle(1));
	}
	write_map(area, map);
	free(area);
	return (0);
}

void	write_map(char *area, t_map map)
{
	int i;

	i = 0;
	while (i < map.hei)
	{
		write(1, area + (i * map.wid), map.wid);
		write(1, "\n", 2);
		i++;
	}
}

int	start_obj(t_map map, char *area, FILE *file)
{
	t_obj	obj;
	int		check;

	check = fscanf(file, "%c %f %f %f %c\n", &obj.type, &obj.x, &obj.y, &obj.radius, &obj.shape);
	while (check == 5)
	{
		if(check_obj(obj) == 1)
			return (1);
		paint_obj(area, obj, map);
		check = fscanf(file, "%c %f %f %f %c\n", &obj.type, &obj.x, &obj.y, &obj.radius, &obj.shape);
	}
	if (check != -1)
		return (1);
	return (0);
}

int	check_obj(t_obj obj)
{
	if (obj.radius <= 0.0)
		return (1);
	if (obj.type != 'c' && obj.type != 'C')
		return (1);
	return (0);
}

void	paint_obj(char *area, t_obj obj, t_map map)
{
	int	i;
	int	j;
	int flag;

	i = 0;
	flag = 0;
	while (i < map.hei)
	{
		j = 0;
		while (j < map.wid)
		{
			flag = check_flag((float)j, (float)i, obj);
			if (flag == 1 && obj.type == 'c')
				area[(i * map.wid) + j] = obj.shape;
			if (flag == 2 && obj.type == 'C')
				area[(i * map.wid) + j] = obj.shape;
			j++;
		}
		i++;
	}
}

int	check_flag(float x, float y, t_obj obj)
{
	float	len;

	len = sqrtf(powf(x - obj.x, 2.) + powf(y - obj.y, 2.));
	if (len <= obj.radius)
	{
		if (obj.radius - len < 1.0)
			return (1);
		return (2);
	}
	return (0);
}

void	paint_ground(char *area, int max, char c)
{
	int	i;

	i = 0;
	while (i < max)
	{
		area[i] = c;
		i++;
	}
}

int	read_map(FILE *file, t_map *map)
{
	int	check;

	check = fscanf(file, "%d %d %c\n", &map->wid, &map->hei, &map->ground);
	if (check != 3)
		return (1);
	return (0);
}

int	error_handle(int cas)
{
	char	*str1 = "Error: argument\n";
	char	*str2 = "Error: Operation file corrupted\n";
	
	if (cas == 0)
		write(1, str1, 17);
	else
		write(1, str2, 33);
	return (1);
}