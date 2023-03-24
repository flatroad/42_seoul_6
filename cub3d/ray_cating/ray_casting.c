#include "data.h"

void	*draw_game_img(t_image game_img, t_data *data)
{
	draw_ceiling(game_img, data->texture->ceiling);
	draw_floor(game_img, data->texture->floor);
	draw_other(game_img, data);
}

void	draw_other(t_image game_img, t_data *data)
{
	ray_casting(game_img, data);
}

void	ray_casting(t_image game_img, t_data *data)
{
	int	x;

	x = 0;
	while (x < G_W)
	{
		
	}
}