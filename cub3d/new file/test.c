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
	*(unsigned int*)dst = color;
}
int main()
{
	void	*mlx;
	void	*win_ptr;
	t_img_data img;
	t_img_data map;
	int w;
	int h;

	mlx = mlx_init();
	win_ptr = mlx_new_window(mlx, 640, 480, "test");
	img.img = mlx_xpm_file_to_image(mlx, "E_wall.xpm", &w, &h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	map.img = mlx_new_image(mlx, 640, 480);
	map.addr = mlx_get_data_addr(map.img, &map.bits_per_pixel, &map.line_length, &map.endian);
	int i = 0;
	while (i < 10)
	{
		my_mlx_pixel_put(&map, i, 8, img.addr);
		i++;
	}
	mlx_put_image_to_window(mlx, win_ptr, map.img, 0, 0);
}
