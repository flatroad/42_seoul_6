/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 07:19:27 by sounchoi          #+#    #+#             */
/*   Updated: 2022/11/26 13:30:02 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initial_map(t_mlx *mlx, char **map, t_err_m err_m)
{
	int	col;
	int	row;

	col = 0;
	while (map[col] != NULL)
	{
		row = 0;
		while (map[col][row] != 10 && map[col][row] != 0)
		{
			if (print_map(mlx, map[col][row], col, row) == 0)
				error_handle_mlx(4, err_m);
			row++;
		}
		row = 0;
		col++;
	}
}

int	print_map(t_mlx *mlx, char c, int col, int row)
{
	if (ft_charcmp(c, 'P') == 0)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
		mlx->player_img, TILE_SIZE * row, TILE_SIZE * col);
	else if (ft_charcmp(c, 'E') == 0)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
		mlx->out_img, TILE_SIZE * row, TILE_SIZE * col);
	else if (ft_charcmp(c, 'C') == 0)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
		mlx->collect_img, TILE_SIZE * row, TILE_SIZE * col);
	else if (ft_charcmp(c, '1') == 0)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
		mlx->wall_img, TILE_SIZE * row, TILE_SIZE * col);
	else if (ft_charcmp(c, '0') == 0)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
		mlx->zero_img, TILE_SIZE * row, TILE_SIZE * col);
	else
		return (0);
	return (1);
}
