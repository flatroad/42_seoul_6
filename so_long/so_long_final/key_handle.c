/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:21:29 by sounchoi          #+#    #+#             */
/*   Updated: 2022/11/27 19:25:14 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hendle(int key_num, t_mlx *mlx)
{
	if (key_num == ESC)
		esc_mlx(mlx);
	if (mlx->obj->way_out != 0)
	{
		if (key_num == W)
			move(mlx->obj, mlx, -1, 0);
		else if (key_num == A)
			move(mlx->obj, mlx, 0, -1);
		else if (key_num == S)
			move(mlx->obj, mlx, 1, 0);
		else if (key_num == D)
			move(mlx->obj, mlx, 0, 1);
	}
	return (0);
}

void	esc_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	write(1, "ESC\n", 4);
	exit(0);
}

void	move(t_gm_obj *obj, t_mlx *mlx, int col, int row)
{
	int	i;
	int	j;
	int	flag;

	i = obj->start_col;
	j = obj->start_row;
	flag = check_move(obj->map, obj, i + col, j + row);
	if (flag == 0)
		return ;
	else
	{
		if (obj->map[obj->start_col][obj->start_row] == 'E')
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
			mlx->out_img, TILE_SIZE * j, TILE_SIZE * i);
		else
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
			mlx->zero_img, TILE_SIZE * j, TILE_SIZE * i);
		exec_move(mlx, col + i, row + j, flag);
		obj->start_col = obj->start_col + col;
		obj->start_row = obj->start_row + row;
	}
}

int	check_move(char **map, t_gm_obj *obj, int col, int row)
{
	char	c;

	c = map[col][row];
	if (c == '1')
		return (0);
	else if (c == '0')
		return (1);
	else if (c == 'C')
	{
		obj->collection--;
		map[col][row] = '0';
		return (2);
	}
	else if (c == 'E' && obj->collection == 0)
	{
		obj->way_out--;
		return (3);
	}
	else if (c == 'E' && obj->collection != 0)
		return (4);
	else if (obj->foe)
		return (5);
	return (0);
}

void	exec_move(t_mlx *mlx, int col, int row, int flag)
{
	char	*str;

	if (flag == 1)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
		mlx->player_img, TILE_SIZE * row, TILE_SIZE * col);
	else if (flag == 2)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
		mlx->player_img, TILE_SIZE * row, TILE_SIZE * col);
	else if (flag == 3)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
		mlx->end_img, TILE_SIZE * row, TILE_SIZE * col);
	else if (flag == 4)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
		mlx->player_house_img, TILE_SIZE * row, TILE_SIZE * col);
	mlx->step++;
	str = ft_itoa(mlx->step);
	write(1, str, (int)ft_strlen(str));
	write(1, "\n", 1);
	free(str);
	str = 0;
	if (flag == 3)
		write(1, "clear\n", 6);
}
