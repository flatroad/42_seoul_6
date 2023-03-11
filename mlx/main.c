#include "minilibx_mms_20210621/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main()
{
	void	*mlx;
	void	*ptr;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	ptr = mlx_new_window(mlx, 640, 480, "test");
	img1 = mlx_xpm_file_to_image(mlx, "N_wall.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, "S_wall.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, "E_wall.xpm", &img_width, &img_height);
	img4 = mlx_xpm_file_to_image(mlx, "W_wall.xpm", &img_width, &img_height);
	img5 = mlx_new_image(mlx,600, 400);
	mlx_put_image_to_window(mlx, ptr, img1, 0, 0);
	mlx_put_image_to_window(mlx, ptr, img2, 64, 0);
	mlx_put_image_to_window(mlx, ptr, img3, 128, 0);
	mlx_put_image_to_window(mlx, ptr, img4, 192, 0);
	mlx_loop(mlx);
	return (0);
}
