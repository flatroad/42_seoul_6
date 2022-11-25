/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 06:12:25 by sounchoi          #+#    #+#             */
/*   Updated: 2022/11/26 08:03:37 by sounchoi         ###   ########.fr       */
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
	mlx_hook(mlx.win_ptr, KEY_PRESS, 0, &key_hendle, &mlx);
	mlx_loop(mlx.mlx_ptr);
}

int	key_hendle(int key_num, t_mlx *mlx, t_gm_obj *obj)
{
	char	**map;

	if (key_num == ESC)
		esc_mlx(mlx);
	if (obj->way_out != 0)
		return (0);
	return (0);

}

void	esc_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	write(1, "ESC\n", 4);
	exit(0);
}