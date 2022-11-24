/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 06:12:25 by sounchoi          #+#    #+#             */
/*   Updated: 2022/11/25 07:17:38 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exec_game(t_gm_obj *obj)
{
	t_err_m	err_m;
	t_mlx	mlx;

	init_error_mlx(&err_m);
	init_mlx(&mlx, obj, err_m);
	init_mlx_images(&mlx, obj, err_m);
	initial_map(&mlx, obj->map, err_m);
	mlx_loop(mlx.mlx_ptr);
}


void	initial_map(t_mlx *mlx, char **map, t_err_m err_m)
{
	int	i;
	int j;

	i = 0;
	while(map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != 10 && map[i][j] != 0)
		{
			if(print_map(mlx, map[i][j], i, j) == 0)
				error_handle_mlx(4, err_m);
			j++;
		}
		j = 0;
		i++;
	}
}

int	print_map(t_mlx *mlx, char c, int i, int j)
{
	if (ft_charcmp(c, 'P') == 0)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
		mlx->player_img, TILE_SIZE * j, TILE_SIZE * i);
	else if (ft_charcmp(c, 'E') == 0)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
		mlx->out_img, TILE_SIZE * j, TILE_SIZE * i);
	else if (ft_charcmp(c, 'C') == 0)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
		mlx->collect_img, TILE_SIZE * j, TILE_SIZE * i);
	else if (ft_charcmp(c, '1') == 0)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
		mlx->wall_img, TILE_SIZE * j, TILE_SIZE * i);
	else if (ft_charcmp(c, '0') == 0)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
		mlx->zero_img, TILE_SIZE * j, TILE_SIZE * i);
	else
		return (0);
	return (1);
}