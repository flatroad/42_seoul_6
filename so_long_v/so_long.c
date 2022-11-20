/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younkim <younkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 05:18:32 by younkim           #+#    #+#             */
/*   Updated: 2022/07/07 10:55:27 by younkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	normal_termination(t_mlx *mlx, char *s)
{
	mlx_destroy_window(mlx->mlx, mlx->win_mlx);
	printf("%s\n", s);
	exit (0);
}

int	key_handle(int key_num, t_mlx *mlx)
{
	char	**map;
	int		x;
	int		y;

	map = mlx->info->map;
	x = mlx->info->start_x;
	y = mlx->info->start_y;
	if (key_num == KEY_ESC)
		normal_termination(mlx, "input esc key");
	if (mlx->info->arrive == 0)
	{
		if (key_num == KEY_W)
			mlx->info->arrive = key_move_w(mlx, map, x, y);
		else if (key_num == KEY_S)
			mlx->info->arrive = key_move_s(mlx, map, x, y);
		else if (key_num == KEY_A)
			mlx->info->arrive = key_move_a(mlx, map, x, y);
		else if (key_num == KEY_D)
			mlx->info->arrive = key_move_d(mlx, map, x, y);
	}
	return (0);
}

int	shutdown(t_mlx *mlx)
{
	normal_termination(mlx, "x button click");
	return (0);
}

int	is_extention(char *s)
{
	int	s_size;

	s_size = ft_strlen(s);
	s_size -= 4;
	if (s_size <= 0)
		return (1);
	return (ft_strcmp(s + s_size, ".ber"));
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;
	t_map	info;
	int		fd;

	if (argc < 2 || is_extention(argv[1]))
		file_error("Error\nnot map");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		file_error("Error\nnot map");
	info.map = read_split(fd);
	mlx.info = &info;
	info.steps = 0;
	info.arrive = 0;
	close(fd);
	check_map(&info);
	mlx_setting(&mlx);
	mlx_hook(mlx.win_mlx, KEY_PRESS, 0, &key_handle, &mlx);
	mlx_hook(mlx.win_mlx, X_BUTTON, 0, &shutdown, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
