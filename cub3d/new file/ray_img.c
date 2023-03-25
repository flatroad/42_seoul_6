#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include "minilibx_mms_20210621/mlx.h"

#define screenWidth 640
#define screenHeight 480
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24

typedef struct s_img_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

typedef	struct s_mlx
{
	void *mlx;
	void *win_ptr;
	int	wid;
	int	hei;
	t_img_data img[4];
} t_mlx;

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

unsigned int	get_color(t_img_data *data, int x, int y)
{
	char	*dst;
	int		color;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	color = *(unsigned int* )dst;

	return (color);
}

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
  {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
  {1,0,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1},
  {1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,1,0,0,0,1,1,1,1},
  {1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
  {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
  {1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,1,1,1,1},
  {1,0,0,0,0,0,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1},
  {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,1,0,1,1},
  {1,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1},
  {1,0,0,1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,1,0,1,1},
  {1,0,1,0,1,0,0,0,0,1,1,0,1,1,0,0,1,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	init_t_mlx(t_mlx *mlx)
{
	int	x;
	int	y;
	mlx->hei = 480;
	mlx->wid = 640;
	mlx->mlx = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx, mlx->wid, mlx->hei, "test");
	mlx->img->bits_per_pixel = 0;
	mlx->img[0].img = mlx_xpm_file_to_image(mlx->mlx, "E_wall.xpm", &x, &y);
	mlx->img[0].addr = mlx_get_data_addr(mlx->img[0].img, &mlx->img[0].bits_per_pixel, &mlx->img[0].line_length, &mlx->img[0].endian);
	mlx->img[1].img = mlx_xpm_file_to_image(mlx->mlx, "W_wall.xpm", &x, &y);
	mlx->img[1].addr = mlx_get_data_addr(mlx->img[1].img, &mlx->img[1].bits_per_pixel, &mlx->img[1].line_length, &mlx->img[1].endian);
	mlx->img[2].img = mlx_xpm_file_to_image(mlx->mlx, "S_wall.xpm", &x, &y);
	mlx->img[2].addr = mlx_get_data_addr(mlx->img[2].img, &mlx->img[2].bits_per_pixel, &mlx->img[2].line_length, &mlx->img[2].endian);
	mlx->img[3].img = mlx_xpm_file_to_image(mlx->mlx, "N_wall.xpm", &x, &y);
	mlx->img[3].addr = mlx_get_data_addr(mlx->img[3].img, &mlx->img[3].bits_per_pixel, &mlx->img[3].line_length, &mlx->img[3].endian);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_img_data game;

	double pos_x = 22.0;
	double pos_y = 11.5;
	double dir_x = -1.0;
	double dir_y = 0.0;
	double plane_x = 0.0;
	double plane_y = 0.66;

	double time = 0;
	double old_time = 0;
	init_t_mlx(&mlx);
	game.img = mlx_new_image(mlx.mlx, 640, 480);
	game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel, &game.line_length, &game.endian);
	printf("%d\n", game.bits_per_pixel);
	printf("%d\n", game.line_length);
	printf("%d\n", game.endian);
	for (int y = 0; y < mlx.hei / 2; y++)
	{
		for (int x = 0; x < mlx.wid; x++)
			my_mlx_pixel_put(&game, x, y, 0x005555DD);
	}
	for (int y = mlx.hei / 2; y < mlx.hei; y++)
	{
		for (int x = 0; x < mlx.wid; x++)
			my_mlx_pixel_put(&game, x, y, 0x00342342);
	}
	for (int x = 0; x < mlx.wid; x++)
	{
		double camera_x = (2 * x) / (double)mlx.wid - 1;
		double ray_dir_x = dir_x + (plane_x * camera_x);
		double ray_dir_y = dir_y + (plane_y * camera_x);

		int map_x = (int)pos_x;
		int map_y = (int)pos_y;

		double side_dist_x;
		double side_dist_y;

		// double delta_dist_x = sqrt(1 + ((ray_dir_y * ray_dir_y) / (ray_dir_x * ray_dir_x)));
		// double delta_dist_y = sqrt(1 + ((ray_dir_x * ray_dir_x) / (ray_dir_y * ray_dir_y)));
		double delta_dist_x = fabs(1 / ray_dir_x);
		double delta_dist_y = fabs(1 / ray_dir_y);

		double perp_wall_dist;

		int step_x;
		int step_y;

		int hit = 0;
		int side;

		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - pos_y) * delta_dist_y;
		}
		
		int dir = 0;
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (worldMap[map_x][map_y] > 0)
			{
				if (side == 1)
				{
					if (map_y > pos_y)
						dir = 0; //동 E
					else
						dir = 1; //서 W
				}
				else
				{
					if (map_x > pos_x)
						dir = 2; //남 S
					else
						dir = 3; //북 N
				}
				hit = 1;
			}
		}

		// if (side == 0)
		// 	perp_wall_dist = (map_x - pos_x + (map_x - pos_x + (1 - step_x) / 2) / ray_dir_x);
		// else
		// 	perp_wall_dist = (map_y - pos_y + (map_y - pos_y + (1 - step_y) / 2) / ray_dir_y);
		
		if (side == 0)
			perp_wall_dist = (side_dist_x - delta_dist_x);
		else
			perp_wall_dist = (side_dist_y - delta_dist_y);
		
		int	line_height = (int)(mlx.hei / perp_wall_dist);
		int draw_start = (-line_height / 2) + (mlx.hei / 2);
      	if(draw_start < 0)
				draw_start = 0;
      	int draw_end = (line_height / 2) + (mlx.hei / 2);
      	if(draw_end >= mlx.hei)
			draw_end = mlx.hei - 1;

		double wall_x;
		if (side == 0)
			wall_x = pos_y + (perp_wall_dist * ray_dir_y);
		else
			wall_x = pos_x + (perp_wall_dist * ray_dir_x);
		wall_x -= floor(wall_x);
		double k = (wall_x * (double)texWidth);
		int tex_x = (int)k;
		if (side == 0 && ray_dir_x > 0 || side == 1 && ray_dir_y < 0)
			tex_x = texWidth - tex_x - 1;
		double step = 1.0 * texHeight / line_height;
		double tex_pos = (draw_start - (mlx.hei / 2) + (line_height / 2)) * step;
		for (int y = draw_start; y < draw_end;)
		{
			y++;
			int color;
			int tex_y = (int)tex_pos & (texHeight - 1);
			tex_pos += step;

			color = get_color(&mlx.img[dir], tex_x, tex_y);
			my_mlx_pixel_put(&game, x, y, color);
		}
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win_ptr, game.img, 0, 0);

	mlx_loop(mlx.mlx);
}