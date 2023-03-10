#include "minilibx_mms_20210621/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main()
{
	void	*mlx;
	void	*ptr;

	mlx = mlx_init();
	ptr = mlx_new_window(mlx, 1920, 1280, "test");
	mlx_pixel_put(mlx, ptr, 1, 1, 0x00FF0000);
	mlx_pixel_put(mlx, ptr, 2, 1, 0x00FF0000);
	mlx_pixel_put(mlx, ptr, 3, 1, 0x00FF0000);
	mlx_pixel_put(mlx, ptr, 4, 1, 0x00FF0000);
	mlx_pixel_put(mlx, ptr, 5, 1, 0x00FF0000);
	mlx_pixel_put(mlx, ptr, 5, 2, 0x00FF0000);
	mlx_pixel_put(mlx, ptr, 1, 2, 0x00FF0000);
	mlx_pixel_put(mlx, ptr, 2, 2, 0x00FF0000);
	mlx_pixel_put(mlx, ptr, 3, 2, 0x00FF0000);
	mlx_pixel_put(mlx, ptr, 4, 2, 0x00FF0000);
	mlx_loop(mlx);
	return (0);
}
