#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_map
{
	int		wid;
	int		hei;
	char	ground;
}	t_map;

typedef struct	s_obj
{
	char			type;
	float			x;
	float			y;
	float			wid;
	float			hei;
	char			draw;
}	t_obj;

void	paint_ground(char *area, int max, char c);
int		get_map(FILE *file, t_map *map);
int		check_map(t_map map);
int		error_handle(int flag);
int		paint_obj(FILE *file, char *area, t_map map);
int 	check_obj(t_obj obj);
int		check_flag(float x, float y, t_obj obj);
void	paint_area(char *area, t_obj obj, t_map map);
void	show_map(char *area, t_map map);


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

int	get_map(FILE *file, t_map *map)
{
	int	check;

	check = fscanf(file, "%d %d %c\n", &map->wid, &map->hei, &map->ground);
	if (check != 3)
		return (1);
	return (0);
}

int	check_map(t_map map)
{
	if (map.wid <= 0 || map.wid > 300)
		return (1);
	if (map.hei <= 0 || map.hei > 300)
		return (1);
	return (0);
}

int	error_handle(int flag)
{
	if (flag == 0)
		write(1, "Error: argument\n", 17);
	else
		write(1, "Error: Operation file corrupted\n", 33);
	return (1);
}

int	paint_obj(FILE *file, char *area, t_map map)
{
	t_obj	obj;
	int		check;
	
	check = fscanf(file, "%c %f %f %f %f %c\n", &obj.type, &obj.x, &obj.y, &obj.wid, &obj.hei, &obj.draw);
	while (check == 6)
	{
		if (check_obj(obj) == 1)
			return (1);
		paint_area(area, obj, map);
		check = fscanf(file, "%c %f %f %f %f %c\n", &obj.type, &obj.x, &obj.y, &obj.wid, &obj.hei, &obj.draw);
	}
	if (check != -1)
		return (1);
	return (0);
}

int check_obj(t_obj obj)
{
	if (obj.wid <= 0.0 || obj.hei <= 0.0)
		return (1);
	if (obj.type != 'r' && obj.type != 'R')
		return (1);
	return (0);
}

int	check_flag(float x, float y, t_obj obj)
{
	if (x < obj.x || obj.x + obj.wid < x || y < obj.y || obj.y + obj.hei < y)
		return (0);
	if (x - obj.x < 1.0 || obj.x + obj.wid - x < 1.0 || y - obj.y < 1.0 || obj.y + obj.hei - y < 1.0)
		return (1);
	return (2);
}

void	paint_area(char *area, t_obj obj, t_map map)
{
	int	i;
	int	j;
	int flag;

	i = 0;
	while (i < map.hei)
	{
		j = 0;
		while (j < map.wid)
		{
			flag = check_flag((float)j, (float)i, obj);
			if (obj.type == 'r' && flag == 1)
				area[(i * map.wid) + j] = obj.draw;
			else if (obj.type == 'R' && flag == 2)
				area[(i * map.wid) + j] = obj.draw;
			j++; 
		}
		i++;
	}
}

void	show_map(char *area, t_map map)
{
	int	i;
	
	i = 0;
	while (i < map.hei)
	{
		write(1, area + (i * map.wid), map.wid);
		write(1, "\n", 2);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_map	map;
	FILE	*file;
	char	*area;

	if (argc != 2)
		return (error_handle(0));
	file = fopen(argv[1], "r");
	if (file == NULL)
		return (error_handle(1));
	if(get_map(file, &map) == 1)
	{
		fclose(file);
		return (error_handle(1));
	}
	if (check_map(map) == 1)
	{
		fclose(file);
		return (error_handle(1));
	}
	area = (char *)malloc(sizeof(char) * (map.hei * map.wid));
	if (area == NULL)
	{
		fclose(file);
		return (error_handle(1));
	}
	paint_ground(area, (map.hei * map.wid), map.ground);
	if (paint_obj(file, area, map) == 1)
	{
		free(area);
		fclose(file);
		return (error_handle(1));
	}
	show_map(area, map);
	free(area);
	fclose(file);
	return (0);
}
