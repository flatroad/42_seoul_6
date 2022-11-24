/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 06:12:25 by sounchoi          #+#    #+#             */
/*   Updated: 2022/11/25 07:51:01 by sounchoi         ###   ########.fr       */
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
