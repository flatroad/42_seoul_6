/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 06:10:37 by sounchoi          #+#    #+#             */
/*   Updated: 2022/11/26 13:08:12 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pull_mlx(t_mlx *mlx, t_gm_obj *obj, t_err_m err_m)
{
	int	width;
	int	height;

	mlx->obj = obj;
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		error_handle_mlx(1, err_m);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, (obj->row_max) * TILE_SIZE, \
	(obj->col_max + 1) * TILE_SIZE, "so_long");
	if (mlx->win_ptr == NULL)
		error_handle_mlx(2, err_m);
}

void	pull_mlx_images(t_mlx *mlx, t_gm_obj *obj, t_err_m err_m)
{
	int	width;
	int	height;

	mlx->player_img = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"images/player.xpm", &width, &height);
	mlx->collect_img = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"images/collection.xpm", &width, &height);
	mlx->end_img = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"images/game_clear.xpm", &width, &height);
	mlx->out_img = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"images/way_out.xpm", &width, &height);
	mlx->wall_img = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"images/wall.xpm", &width, &height);
	mlx->zero_img = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"images/zero.xpm", &width, &height);
	mlx->player_house_img = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"images/player_house.xpm", &width, &height);
	if (mlx->player_img || mlx->collect_img || mlx->end_img || mlx->out_img \
	|| mlx->wall_img || mlx->zero_img || mlx->player_house_img)
		return ;
	else
		error_handle_mlx(3, err_m);
}
