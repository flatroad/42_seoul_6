#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_map
{
	int		wid;
	int		hei;
	char	ground;
}	t_map;

typedef	struct	s_obj
{
	 char	type;
	 float	x;
	 float	y;
	 float	wid;
	 float	hei;
	 char	shape;
}	t_obj;


int		error_handle(int cas);
int		start_paint(FILE *file);
int		file_map_data(FILE *file, t_map *map);
int		check_map_data(t_map map);
void	paint_ground(char *area, int max, char c);
void	write_area(char *area, t_map map);
int		make_obj(t_map map, char *area, FILE *file);
void	paint_obj(t_map map, char *area, t_obj obj);
int		check_flag(float x, float y, t_obj obj);
int		check_obj(t_obj obj);

int main(int argc, char **argv)
{
	FILE	*file;

	if (argc != 2)
		return (error_handle(0));
	file = fopen(argv[1], "r");
	if (file == 0)
		return (error_handle(1));
	if(start_paint(file) == 1)
	{
		fclose(file);
		return (error_handle(1));
	}
	fclose(file);
	return (0);

}



// -----------------------------------------------



int	start_paint(FILE *file)
{
	t_map	map;
	char	*area;

	if (file_map_data(file, &map) == 1)
		return (1);
	if (check_map_data(map) == 1)
		return (1);
	area = (char *)malloc(sizeof(char) * (map.hei * map.wid));
	if (area == NULL)
		return (1);
	paint_ground(area, (map.hei * map.wid), map.ground);
	if (make_obj(map, area, file) == 1)
	{
		free(area);
		return (1);
	}
	write_area(area, map);
	free(area);
	return (0);
}

void	write_area(char *area, t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.hei)
	{
		write(1, area + (map.wid * i), map.wid);
		write(1, "\n", 2);
		i++;
	}
}

int	make_obj(t_map map, char *area, FILE *file)
{
	t_obj	obj;
	int		check;

	check = fscanf(file, "%c %f %f %f %f %c\n", &obj.type, &obj.x, &obj.y, &obj.wid, &obj.hei, &obj.shape);
	while (check == 6)
	{
		if (check_obj(obj) == 1)
			return (1);
		paint_obj(map, area, obj);
		check = fscanf(file, "%c %f %f %f %f %c\n", &obj.type, &obj.x, &obj.y, &obj.wid, &obj.hei, &obj.shape);
	}
	if (check != -1)
		return (1);
	return (0);
}

int	check_obj(t_obj obj)
{
	if (obj.hei <= 0.0 || obj.wid <= 0.0)
		return (1);
	if (obj.type != 'r' && obj.type != 'R')
		return (1);
	return (0);
}

void	paint_obj(t_map map, char *area, t_obj obj)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (i < map.hei)
	{
		j  = 0;
		while (j < map.wid)
		{
			flag = check_flag((float)j, (float)i, obj);
			if (flag == 1 && obj.type == 'r')
				area[(i * map.wid) + j] = obj.shape;
			if (flag == 2 && obj.type == 'R')
				area[(i * map.wid) + j] = obj.shape;
			j++;
		}
		i++;
	}
}

int	check_flag(float x, float y, t_obj obj)
{
	if (x < obj.x || y < obj.y || obj.x + obj.wid < x || obj.y + obj.hei < y)
		return (0);
	if (x - obj.x < 1.0 || y - obj.y < 1.0 || (obj.x + obj.wid) - x < 1.0 || (obj.y + obj.hei) - y < 1.0)
		return (1);
	return (2);
}


// ----------------------------------------------

int	error_handle(int cas)
{
	char *str1 = "Error: argument\n";
	char *str2 = "Error: Operation file corrupted\n";

	if (cas == 0)
		write(1, str1, 17);
	else
		write(1, str2, 33);
	return (1);
}

int	file_map_data(FILE *file, t_map *map)
{
	int	check;

	check = fscanf(file, "%d %d %c\n", &map->wid, &map->hei, &map->ground);
	if (check != 3)
		return (1);
	return (0);
}

int	check_map_data(t_map map)
{
	if (map.hei > 300 || map.hei <= 0)
		return (1);
	if (map.wid > 300 || map.wid <= 0)
		return (1);
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