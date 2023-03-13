#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "minilibx_mms_20210621/mlx.h"

typedef struct s_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main()
{
	void	*mlx;
	void	*win_ptr;
	t_data	data;
	
	mlx = mlx_init();
	win_ptr = mlx_new_window(mlx, 640, 480, "test");
	data.img = mlx_new_image(mlx, 640, 480);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	for (int i = 0; i < 150; i = i + 15)
	{
		for (int j = 0; j < 150; j = j + 15)
		{
			my_mlx_pixel_put(&data, j, i, 0x00FFFFFF);
		}
	}
	mlx_put_image_to_window(mlx, win_ptr, data.img, 0, 0);
	mlx_loop(mlx);

}