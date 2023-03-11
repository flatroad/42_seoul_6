#include "minilibx_mms_20210621/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main()
{
	void	*mlx;
	void	*ptr;
	void	*img;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	ptr = mlx_new_window(mlx, 1920, 1280, "test");
	img = mlx_xpm_file_to_image(mlx, "mini.xpm", &img_width, &img_height);
	printf("%p\n", img);
	mlx_put_image_to_window(mlx, ptr, img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
