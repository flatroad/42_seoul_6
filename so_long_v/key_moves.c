/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younkim <younkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 00:07:04 by younkim           #+#    #+#             */
/*   Updated: 2022/07/04 02:41:33 by younkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_move_w(t_mlx *mlx, char **map, int x, int y)
{
	if (map[y - 1][x] == '1')
		return (0);
	if (map[y - 1][x] == 'E' && mlx->info->c_cnt != 0)
	{
		printf("collect not zero\n");
		return (0);
	}
	if (map[y - 1][x] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, \
			mlx->end_img, x * TILE_SIZE, (y - 1) * TILE_SIZE);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, \
			mlx->start_img, x * TILE_SIZE, (y - 1) * TILE_SIZE);
	mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, \
		mlx->zero_img, x * TILE_SIZE, y * TILE_SIZE);
	if (map[y - 1][x] == 'C')
		mlx->info->c_cnt--;
	map[y][x] = '0';
	mlx->info->start_y--;
	mlx->info->steps++;
	printf("%d\n", mlx->info->steps);
	if (map[y - 1][x] == 'E' && mlx->info->c_cnt == 0)
		return (1);
	return (0);
}

int	key_move_s(t_mlx *mlx, char **map, int x, int y)
{
	if (map[y + 1][x] == '1')
		return (0);
	if (map[y + 1][x] == 'E' && mlx->info->c_cnt != 0)
	{
		printf("collect not zero\n");
		return (0);
	}
	if (map[y + 1][x] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, \
			mlx->end_img, x * TILE_SIZE, (y + 1) * TILE_SIZE);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, \
			mlx->start_img, x * TILE_SIZE, (y + 1) * TILE_SIZE);
	mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, \
		mlx->zero_img, x * TILE_SIZE, y * TILE_SIZE);
	if (map[y + 1][x] == 'C')
		mlx->info->c_cnt--;
	map[y][x] = '0';
	mlx->info->start_y++;
	mlx->info->steps++;
	printf("%d\n", mlx->info->steps);
	if (map[y + 1][x] == 'E' && mlx->info->c_cnt == 0)
		return (1);
	return (0);
}

int	key_move_a(t_mlx *mlx, char **map, int x, int y)
{
	if (map[y][x - 1] == '1')
		return (0);
	if (map[y][x - 1] == 'E' && mlx->info->c_cnt != 0)
	{
		printf("collect not zero\n");
		return (0);
	}
	if (map[y][x - 1] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, \
			mlx->end_img, (x - 1) * TILE_SIZE, y * TILE_SIZE);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, \
			mlx->start_img, (x - 1) * TILE_SIZE, y * TILE_SIZE);
	mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, \
		mlx->zero_img, x * TILE_SIZE, y * TILE_SIZE);
	if (map[y][x - 1] == 'C')
		mlx->info->c_cnt--;
	map[y][x] = '0';
	mlx->info->start_x--;
	mlx->info->steps++;
	printf("%d\n", mlx->info->steps);
	if (map[y][x - 1] == 'E' && mlx->info->c_cnt == 0)
		return (1);
	return (0);
}

int	key_move_d(t_mlx *mlx, char **map, int x, int y)
{
	if (map[y][x + 1] == '1')
		return (0);
	if (map[y][x + 1] == 'E' && mlx->info->c_cnt != 0)
	{
		printf("collect not zero\n");
		return (0);
	}
	if (map[y][x + 1] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, \
			mlx->end_img, (x + 1) * TILE_SIZE, y * TILE_SIZE);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, \
			mlx->start_img, (x + 1) * TILE_SIZE, y * TILE_SIZE);
	mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, \
		mlx->zero_img, x * TILE_SIZE, y * TILE_SIZE);
	if (map[y][x + 1] == 'C')
		mlx->info->c_cnt--;
	map[y][x] = '0';
	mlx->info->start_x++;
	mlx->info->steps++;
	printf("%d\n", mlx->info->steps);
	if (map[y][x + 1] == 'E' && mlx->info->c_cnt == 0)
		return (1);
	return (0);
}
