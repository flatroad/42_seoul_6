#include "cub3d.h"


#include <string.h>

typedef struct s_map
{
	int		xsize;
	int		ysize;
	char	**map;
}	t_map;

typedef struct	s_map_obj
{
	int	player;
}	t_map_obj;

int	map_vaildity(t_map *map_data, t_map_obj *map_obj);
int	check_outline_point(t_map *map_data, int y, int x);
int	check_four_point(t_map *map_data, int y, int x);
void	map_obj_init(t_map_obj *map_obj);
void	insert_map_obj(t_map_obj *map, char c);

int	main()
{
	t_map		map_data;
	t_map_obj	map_obj;
	char		**str;

	str = malloc(sizeof(char *) * 5);
	str[0] = "1111";
	str[1] = "1001";
	str[2] = "1111";
	str[3] = "  1 ";
	str[4] = NULL;

	map_data.map = str;
	map_data.xsize = 5;
	map_data.ysize = 5;
	map_obj_init(&map_obj);
	if(map_vaildity(&map_data, &map_obj) == 1)
	{
		printf("%s\n", "실패");
		exit(0);
	}
	printf("%s\n", "성공");
}

void	map_obj_init(t_map_obj *map_obj)
{
	map_obj->player = 0;
}

int	map_vaildity(t_map *map_data, t_map_obj *map_obj)
{
	int		y;
	int		x;

	y = 0;
	while (y < map_data->ysize - 1)
	{
		x = 0;
		while (x < map_data->xsize - 1)
		{
			insert_map_obj(map_obj, map_data->map[y][x]);
			printf("%s %d %d\n", "test", y ,x);
			if (check_outline_point(map_data, y, x) == 1)
				return (1);
			if (check_four_point(map_data, y, x) == 1)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	insert_map_obj(t_map_obj *map, char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		map->player++;
}

int	check_outline_point(t_map *map_data, int y, int x)
{
	if (y != map_data->ysize - 1 && x != map_data->xsize - 1 && y != 0 && x != 0)
		return (0);
	if (map_data->map[y][x] != '1' && map_data->map[y][x] != ' ')
		return (1);
	return (0);
}

int	check_four_point(t_map *map_data, int y, int x)
{
	printf("y = %d x = %d\n", y, x);
	if (map_data->map[y][x] != ' ')
		return (0);
	if (y > 0 && map_data->map[y - 1][x] != '1' \
		&& map_data->map[y - 1][x] != ' ')
	{
		printf("1 : %c ", map_data->map[y - 1][x]);
		return (1);
	}
	if (y < map_data->ysize - 2 && map_data->map[y + 1][x] != '1' \
		&& map_data->map[y + 1][x] != ' ')
	{
		printf("2 : %c ", map_data->map[y + 1][x]);
		return (1);
	}
	if (x > 0 && map_data->map[y][x - 1] != '1' \
		&& map_data->map[y][x - 1] != ' ')
	{
		printf("3 : %c ", map_data->map[y][x - 1]);
		return (1);
	}
	if (x < map_data->xsize - 2 && map_data->map[y][x + 1] != '1' \
		&& map_data->map[y][x + 1] != ' ')
	{
		printf("4 : %c\n", map_data->map[y][x + 1]);
		return (1);
	}
	return (0);
}
