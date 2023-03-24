#include "data.h"

void	draw_ceiling(t_image game_img, t_rgb ceiling)
{
	int	x;
	int	y;
	int	max;

	y = 0;
	max = G_H / 2;
	while (y < max)
	{
		x = 0;
		while (x < G_W)
		{
			my_mlx_pixel_put(&game_img, x, y, ceiling);
			x++;
		}
		y++;
	}
}

void	draw_floor(t_image game_img, t_rgb floor)
{
	int	x;
	int	y;
	int	max;

	y = G_H / 2;
	max = G_H;
	while (y < max)
	{
		x = 0;
		while (x < G_W)
		{
			my_mlx_pixel_put(&game_img, x, y, floor);
			x++;
		}
		y++;
	}
}
