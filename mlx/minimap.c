#include "minimap.h"

int	minimap(t_map *map_data)
{
	t_mini	mini;

	if (mini_insert(map_data, &mini) == 1)
		return (1);
	if (mini_obj_insert(&mini, map_data) == 1)
	{
		mini_obj_free(&mini, mini.parti_y);
		return (1);
	}
	if (new_image_minimap(&mini) == 1)
	{
		mini_obj_free(&mini, mini.parti_y);
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	new_image_minimap(t_mini *mini)
{
	int	x;
	int	y;

	y = 0;
	while (y < mini->parti_y)
	{
		x = 0;
		while (x < mini->parti_x)
		{
			new_img(mini->mini_obj[y][x].map, mini->mini_obj[y][x].img);
		}
	}
}

int	mew_img(char **map, t_data img)
{
	img.img = 
}