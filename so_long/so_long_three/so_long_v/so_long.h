/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younkim <younkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 05:34:14 by younkim           #+#    #+#             */
/*   Updated: 2022/07/07 10:54:05 by younkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "./mlx/mlx.h"

# define MAX_READ 1000
# define KEY_PRESS 2
# define KEY_W 13
# define KEY_A 0
# define KEY_D 2
# define KEY_S 1
# define KEY_ESC 53
# define TILE_SIZE 64
# define X_BUTTON 17

typedef struct s_map
{
	char	**map;
	int		row;
	int		column;
	int		c_cnt;
	int		start_x;
	int		start_y;
	int		steps;
	int		arrive;
}		t_map;

typedef struct s_mlx
{
	t_map	*info;
	void	*mlx;
	void	*win_mlx;
	void	*start_img;
	void	*wall_img;
	void	*zero_img;
	void	*collect_img;
	void	*out_img;
	void	*end_img;
}	t_mlx;

//key_moves
int		key_move_w(t_mlx *mlx, char **map, int x, int y);
int		key_move_s(t_mlx *mlx, char **map, int x, int y);
int		key_move_a(t_mlx *mlx, char **map, int x, int y);
int		key_move_d(t_mlx *mlx, char **map, int x, int y);

//check_map
void	check_map(t_map *info);

//utils
char	**read_split(int fd);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
int		ft_strcmp(char *s1, char *s2);

//mlx_map_utils
void	mlx_setting(t_mlx *mlx);

//error_handle
void	file_error(char *s);
void	heap_error(char *s);

#endif