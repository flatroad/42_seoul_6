#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include "minilibx_mms_20210621/mlx.h"

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

typedef struct s_img_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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

int main (int argc, char **argv)
{
	t_img_data img;
	void	*mlx;
	void	*win_ptr;
	int wid;
	int hei;

	double pos_x = 22.0;
	double pos_y = 11.5;
	double dir_x = -1;
	double dir_y = 0;
	double plane_x = 0;
	double plane_y = 0.66;
	void *img1;
	void *img2;
	void *img3;
	void *img4;

	double time = 0;
	double old_time = 0;

	mlx = mlx_init();
	win_ptr = mlx_new_window(mlx, 640, 480, "test");
	img1 = mlx_xpm_file_to_image(mlx, "E_wall.xpm", &wid, &hei);
	img2 = mlx_xpm_file_to_image(mlx, "N_wall.xpm", &wid, &hei);
	img3 = mlx_xpm_file_to_image(mlx, "S_wall.xpm", &wid, &hei);
	img4 = mlx_xpm_file_to_image(mlx, "W_wall.xpm", &wid, &hei);
	img.img = mlx_new_image(mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (int x = 0; x < 640; x++)
	{
		double camera_x = 2 * x / (double)640 - 1;
		double ray_dir_x = dir_x + plane_x * camera_x;
		double ray_dir_y = dir_y + plane_y * camera_x;

		int map_x = (int)pos_x;
		int map_y = (int)pos_y;

		double side_dist_x;
		double side_dist_y;

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
				hit = 1;
		}
		if (side == 0)
			perp_wall_dist = (side_dist_x - delta_dist_x);
		else
			perp_wall_dist = side_dist_y - delta_dist_y;

		int line_height = (int)(480 / perp_wall_dist);

		int drawStart = -line_height / 2 + 480 / 2;
      	if(drawStart < 0) 
				drawStart = 0;
      	int drawEnd = line_height / 2 + 480 / 2;
      	if(drawEnd >= 480) 
			drawEnd = 480 - 1;
		int color;
		switch(worldMap[map_x][map_y])
		{
			case 1:  color = 0x00FF0000;    break; //red
        	case 2:  color = 0x0000FF00;  break; //green
        	case 3:  color = 0x000000FF;   break; //blue
        	case 4:  color = 0x00FFFFFF;  break; //white
			default : color = 0x00352345; break;
		}
		if(side == 1) 
		{
			color = color / 2;
		}
		while (drawStart < drawEnd)
		{
			my_mlx_pixel_put(&img, x, drawStart, color);
			drawStart++;
		}
	}
	mlx_put_image_to_window(mlx, win_ptr, img.img, 0, 0);


	mlx_loop(mlx);
}