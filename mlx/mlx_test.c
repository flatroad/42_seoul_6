#include "minilibx_mms_20210621/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main()
{
	void	*mlx;
	void	*ptr;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	t_data	img5;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	ptr = mlx_new_window(mlx, 640, 480, "test");
	img1 = mlx_xpm_file_to_image(mlx, "N_wall.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, "S_wall.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, "E_wall.xpm", &img_width, &img_height);
	img4 = mlx_xpm_file_to_image(mlx, "W_wall.xpm", &img_width, &img_height);
	img5.img = mlx_new_image(mlx, 128, 128);
	img5.addr = mlx_get_data_addr(img5.img, &img5.bits_per_pixel, &img5.line_length, &img5.endian);
	int i = 0;
	while (i < 128)
	{
		int j = 0;
		while (j < 128)
		{
			my_mlx_pixel_put(&img5, i, j, 0x00FFFFFF);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, ptr, img5.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
