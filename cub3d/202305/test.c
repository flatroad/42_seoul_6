#include "libs/MLX/mlx.h"
#include <stdio.h>

typedef struct  s_data
{
    void        *mlx;
    void        *win;
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
	int		mouse_x;
	int		mouse_y;
}               t_data;

int	handle_mouse_move(int x, int y, void *param)
{
    t_data *data;

    data = (t_data *)param;
    data->mouse_x = x;
    data->mouse_y = y;
    printf("Mouse moved to x=%d, y=%d\n", x, y);
    return (0);
}

int	main(void)
{
    void	*mlx;
    void	*win;
    t_data	data;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 640, 480, "My Window");
    data.mlx = mlx;
    data.win = win;
    mlx_hook(win, 6, 0, handle_mouse_move, &data);
    mlx_loop(mlx);
    return (0);
}