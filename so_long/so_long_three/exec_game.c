/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 06:12:25 by sounchoi          #+#    #+#             */
/*   Updated: 2022/11/26 14:10:33 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exec_game(t_gm_obj *obj)
{
	t_err_m	err_m;
	t_mlx	mlx;

	init_error_mlx(&err_m);
	init_mlx(&mlx);
	pull_mlx(&mlx, obj, err_m);
	pull_mlx_images(&mlx, obj, err_m);
	initial_map(&mlx, obj->map, err_m);
	obj->map[obj->start_col][obj->start_row] = '0';
	mlx_hook(mlx.win_ptr, KEY_PRESS, 0, &key_hendle, &mlx);
	mlx_hook(mlx.win_ptr, X_BUTTON, 0, &esc_x, &mlx);
	mlx_loop(mlx.mlx_ptr);
}

int	esc_x(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	write(1, "ESC\n", 4);
	exit (0);
	return (0);
}
