#include "minimap.h"

int	mini_obj_insert(t_mini *mini, t_map *map_data)
{
	if(mini_obj_init(mini) == 1)
		return (1);
	mini_obj_map_insert(mini->mini_obj, map_data);
	return (0);
}

int	mini_obj_init(t_mini *mini)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < mini->parti_y)
	{
		x = 0;
		while (x < mini->parti_x)
		{
			mini->mini_obj[y][x].img = NULL;
			mini->mini_obj[y][x].map = NULL;
			if (mini_obj_map_malloc(&(mini->mini_obj[y][x])) == 1)
				return (1);
			x++;
		}	
		y++;
	}
	return (0);
}

int	mini_obj_map_malloc(t_mini_obj *mini_obj)
{
	int	i;

	i = 0;
	mini_obj->map = (char **)malloc(sizeof(char *) * 11);
	if (mini_obj->map == NULL)
		return (1);
	while (i < 11)
	{
		mini_obj->map[i] = (char *)malloc(sizeof(char) * 11);
		if (mini_obj->map[i] == NULL)
		{
			mini_obj_map_free(mini_obj, i);
			return (1);
		}
		i++;
	}
	return (0);
}

void	mini_obj_map_free(char **map, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	mini_obj_map_insert(t_mini_obj **mini_obj, t_map *map_data)
{
	int	i;
	int	j;
	i = 0;
	while (i < map_data->ysize)
	{
		j = 0;
		while (j < map_data->ysize)
		{
			mini_obj[i / 10][j / 10].map[i % 10][j % 10] = map_data->map[i][j];
			j++;
		}
		i++;
	}
}
